.SILENT:
default:
	cd src && make build
	echo "---- start pizzadb ----\n"
	./pizzadb.out
	echo "\n--- end pizzadb ----"