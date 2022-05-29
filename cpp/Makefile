# Project-specific settings
PROJECT := matchbench

# Flags to use regardless of compiler
CFLAGS_all := -Wall -Wno-unused-function -std=c++17 -Ithird-party/ -Iinclude/

# Native compiler information
CXX ?= g++
CFLAGS_nat := -O3 -DNDEBUG -msse4.2 $(CFLAGS_all)
CFLAGS_nat_debug := -g $(CFLAGS_all)

# Emscripten compiler information
CXX_web := emcc
OFLAGS_web_all := -s "EXTRA_EXPORTED_RUNTIME_METHODS=['ccall', 'cwrap']" -s TOTAL_MEMORY=67108864 --js-library third-party/Empirical/include/emp/web/library_emp.js -s EXPORTED_FUNCTIONS="['_main', '_empCppCallback', '_empDoCppCallback']" -s DISABLE_EXCEPTION_CATCHING=1 -s NO_EXIT_RUNTIME=1 #--embed-file configs
OFLAGS_web := -Oz -DNDEBUG
OFLAGS_web_debug := -g4 -Oz -Wno-dollar-in-identifier-extension

CFLAGS_web := $(CFLAGS_all) $(OFLAGS_web) $(OFLAGS_web_all)
CFLAGS_web_debug := $(CFLAGS_all) $(OFLAGS_web_debug) $(OFLAGS_web_all)

default: $(PROJECT)
native: $(PROJECT)
web: $(PROJECT).js
all: $(PROJECT) $(PROJECT).js

debug: CFLAGS_nat := $(CFLAGS_nat_debug)
debug: $(PROJECT)

debug-web: CFLAGS_web := $(CFLAGS_web_debug)
debug-web: $(PROJECT).js

web-debug: debug-web

benchmark_baseline.o: source/benchmark_baseline.cpp include/
	$(CXX) $(CFLAGS_nat) -Ithird-party/Empirical_baseline/include -c source/benchmark_baseline.cpp -o benchmark_baseline.o

benchmark_control.o: source/benchmark_control.cpp include/
	$(CXX) $(CFLAGS_nat) -Ithird-party/Empirical_control/include -c source/benchmark_control.cpp -o benchmark_control.o

benchmark_fiddle.o: source/benchmark_fiddle.cpp include/
	$(CXX) $(CFLAGS_nat) -Ithird-party/Empirical_fiddle/include -c source/benchmark_fiddle.cpp -o benchmark_fiddle.o

# see https://stackoverflow.com/a/57760267 RE: -lstdc++fs
# benchmark_control.o benchmark_baseline.o benchmark_fiddle.o order
# matters to get a fair benchmark of baseline vs fiddle, presumably
# due to order-dependent effects on which code sections get discarded
# when linking
# see https://stackoverflow.com/a/44346057/17332200
$(PROJECT): source/native.cpp include/ benchmark_baseline.o benchmark_control.o benchmark_fiddle.o
	$(CXX) benchmark_control.o benchmark_baseline.o benchmark_fiddle.o $(CFLAGS_nat) -Ithird-party/Empirical_control/include source/native.cpp -o $(PROJECT)
	@echo To build the web version use: make web

$(PROJECT).js: source/web.cpp include/
	cd third-party/emsdk && . ./emsdk_env.sh && cd - && $(CXX_web) $(CFLAGS_web) source/web.cpp -o web/$(PROJECT).js

docs:
	cd docs && make html

serve:
	python3 -m http.server

clean:
	rm -f $(PROJECT) web/$(PROJECT).js web/*.js.map web/*.js.map *~ source/*.o web/*.wasm web/*.wast *.o

test: debug debug-web
	./matchbench | grep -q 'Hello, world!' && echo 'matched!' || exit 1
	npm install
	echo "const puppeteer = require('puppeteer'); var express = require('express'); var app = express(); app.use(express.static('web')); app.listen(3000); express.static.mime.types['wasm'] = 'application/wasm'; function sleep(millis) { return new Promise(resolve => setTimeout(resolve, millis)); } async function run() { const browser = await puppeteer.launch(); const page = await browser.newPage(); await page.goto('http://localhost:3000/matchbench.html'); await sleep(1000); const html = await page.content(); console.log(html); browser.close(); process.exit(0); } run();" | node | tr -d '\n' | grep -q "Hello, browser!" && echo "matched!" || exit 1
	echo "const puppeteer = require('puppeteer'); var express = require('express'); var app = express(); app.use(express.static('web')); app.listen(3000); express.static.mime.types['wasm'] = 'application/wasm'; function sleep(millis) { return new Promise(resolve => setTimeout(resolve, millis)); } async function run() { const browser = await puppeteer.launch(); const page = await browser.newPage(); page.on('console', msg => console.log(msg.text())); await page.goto('http://localhost:3000/matchbench.html'); await sleep(1000); await page.content(); browser.close(); process.exit(0); } run();" | node | grep -q "Hello, console!" && echo "matched!"|| exit 1

tests:
	cd tests && make
	cd tests && make opt
	cd tests && make fulldebug

coverage:
	cd tests && make coverage

install-test-dependencies:
	git submodule update --init && cd third-party && bash ./install_emsdk.sh && bash ./install_force_cover.sh

.PHONY: tests clean test serve debug native web tests install-test-dependencies documentation-coverage documentation-coverage-badge.json version-badge.json doto-badge.json
