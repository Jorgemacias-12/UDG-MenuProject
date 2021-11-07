compile:
	@echo "Compilando proyecto!"
	@g++ src/main.c src/functions/menuData.c src/functions/menuHandler.c src/functions/utils.c -o dist/main.exe