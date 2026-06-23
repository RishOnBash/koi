# koi
`koi` is a simple file viewer written in C. It works similar to POSIX `cat` but it pretty print the file contents with their respective name and line numbers.

## Installation
```sh
git clone https://github.com/RishOnBash/koi.git
cd koi
make install
```
## Usage
```sh
koi FILE ...
```

### Examples
- Read single file.
```
$ koi file.txt
> file.txt

  1 Hello, World.
  2 I am file.txt.

```

- Read multiple files.
```
$ koi file1.txt file2.txt
> file1.txt
  
  1 Hello, World.
  2 I am file1.txt.
  3 End of File: file1.txt

> file2.txt

  1 Hello, World.
  2 I am file2.txt.
  3 End of File: file2.txt

```

- Pass a glob character to read multiple files
```
$ koi *.sh  # prints all files ending with .sh to STDOUT
```

## Uninstallation

```sh
make uninstall
```

## TODO
- [ ] Read from STDIN
- [ ] Automatic pager

## License
MIT
