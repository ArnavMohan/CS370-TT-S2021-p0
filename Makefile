HFILES := $(wildcard tests/*.h)
TARGES := $(patsubst tests/%.h,%,$(HFILES))
BINOBJ := $(addprefix bin/,$(TARGES))
OUTFIL := $(addprefix out/,$(TARGES))
SRCFIL := src/main.cc src/mathlib.h

all:
	for i in $(OUTFIL); do make $$i; done

bin:
	mkdir -p bin

out:
	mkdir -p out

$(TARGES): % : bin/%

$(BINOBJ): bin/% : tests/%.h $(SRCFIL) bin
	$(eval TMP := $(shell mktemp -d))
	-for i in $(SRCFIL); do cp $$i $(TMP); done
	-cp $< $(TMP)/test.h
	-g++ -std=c++17 $(TMP)/main.cc -o $@ -pthread -O3 -Wall -Werror
	rm -rf $(TMP)

$(OUTFIL): out/% : bin/% out
	$< > $@

clean:
	rm -rf bin/ out/
