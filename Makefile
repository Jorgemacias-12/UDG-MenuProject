run: compileRes compile open

compileRes:
	@windres src/resources/resources.rc -O coff -o dist/data.res

compile:
	@echo "Compilando proyecto!"
	@g++ src/main.c src/functions/menuData.c src/functions/menuHandler.c src/functions/utils.c dist/data.res -o dist/main.exe

open:
	@cd dist/
	@explorer .
