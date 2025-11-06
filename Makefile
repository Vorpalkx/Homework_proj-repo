# Короткие команды для сборки
build-%:
	cd build && cmake --build . --target $*

# Конкретные проекты
bb:
	cd build && cmake --build . --target bracket_balance

sy:
	cd build && cmake --build . --target shunting_yard

all:
	cd build && cmake --build . --target all

# Запуск
run-bb: bb
	./build/src/Advanced\ bracket\ balance/bracket_balance

run-sy: sy
	./build/src/Shunting\ yard/shunting_yard

# Очистка
clean:
	cd build && cmake --build . --target clean

# Конфигурация
configure:
	mkdir -p build && cd build && cmake ..

help:
	@echo "Available targets:"
	@echo "  build-    - abbreviating the 'cmake --build . --target' command"
	@echo "  bb        - Build bracket_balance"
	@echo "  sy        - Build shunting_yard"
	@echo "  run-bb    - Build and run bracket_balance"
	@echo "  run-sy    - Build and run shunting_yard"
	@echo "  clean     - Clean build artifacts"
	@echo "  all       - Build all targets"
	@echo "  configure - Configure CMake"

.PHONY: bb sy run-bb run-sy clean all configure help
