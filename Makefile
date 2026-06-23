CC = gcc
CFLAGS = -Wall -Werror
TARGET = koi
SRC = koi.c

ifdef PREFIX
    INSTALL_DIR = $(PREFIX)/bin
else
    ifeq ($(shell id -u), 0)
        INSTALL_DIR = /usr/local/bin
    else
        INSTALL_DIR = $(HOME)/.local/bin
    endif
endif

all: $(TARGET)

$(TARGET): $(SRC)
	@$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

install: all
	@mkdir -p $(INSTALL_DIR)
	@mv $(TARGET) $(INSTALL_DIR)
	@echo "> Installed: $(TARGET)"

uninstall:
	@rm -f $(INSTALL_DIR)/$(TARGET)
	@echo "> Uninstalled: $(TARGET)"
