INPUT_FILE    := ./data/input.txt
OUTPUT_FILE   := ./data/output.txt
EXPECTED_FILE := ./test/expected.txt

build: reverse.c ./data/input.txt
	@gcc ./reverse.c -o bin/reverse

run: build
	@./bin/reverse < $(INPUT_FILE)

out: build
	./bin/reverse < $(INPUT_FILE) > $(OUTPUT_FILE)

clean:
	rm $(OUTPUT_FILE)

test: build out
	diff $(OUTPUT_FILE) $(EXPECTED_FILE)
