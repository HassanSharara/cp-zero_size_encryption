# ZeroSizeEncryptor

A lightweight C++ encryption library that provides simple XOR-based encryption for various data types with minimal overhead.

## Overview

ZeroSizeEncryptor is a header-only C++ library that offers basic encryption/decryption capabilities for raw bytes, arbitrary data types, arrays, and strings. The library uses a simple key-based algorithm that adds/subtracts a key-derived value to each byte.

## Features

- **Zero overhead**: Template-based design with inline functions
- **Multiple data type support**: Encrypt bytes, structs, arrays, and strings
- **Simple API**: Easy-to-use functions with minimal setup
- **No dependencies**: Pure C++ implementation using only standard library

## Installation

Include the library in your project:

```cpp
#include "zero_size_encryption.h"
```

## Usage

### Basic Byte Array Encryption

```cpp
uint8_t data[] = {1, 2, 3, 4, 5};
const char* key = "my_secret_key";

// Encrypt
ZeroSizeEncryptor::encrypt(data, 5, key);

// Decrypt
ZeroSizeEncryptor::decrypt(data, 5, key);
```

### Encrypting Arbitrary Types

```cpp
struct MyData {
    int value;
    float score;
};

MyData data = {42, 3.14f};
const char* key = "password123";

// Encrypt
ZeroSizeEncryptor::any::encrypt(data, key);

// Decrypt
ZeroSizeEncryptor::any::decrypt(data, key);
```

### Array Encryption

```cpp
int numbers[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
const char* key = "array_key";

// Encrypt
ZeroSizeEncryptor::array::encrypt(numbers, key);

// Decrypt
ZeroSizeEncryptor::array::decrypt(numbers, key);
```

### String Encryption

```cpp
std::string message = "Hello, World!";
const char* key = "string_key";

// Encrypt
ZeroSizeEncryptor::str::encrypt(message, key);

// Decrypt
ZeroSizeEncryptor::str::decrypt(message, key);
```

For C-style strings:

```cpp
char text[] = "Secret message";
const char* key = "cstring_key";

// Encrypt
ZeroSizeEncryptor::str::encrypt_char(text, key);

// Decrypt
ZeroSizeEncryptor::str::decrypt_char(text, key);
```

## API Reference

### Core Functions

- `encrypt<L>(uint8_t* bytes, L length, const char* key)` - Encrypts a byte array
- `decrypt<L>(uint8_t* bytes, L length, const char* key)` - Decrypts a byte array

### Namespace: `any`

- `encrypt<V>(V& v, const char* key)` - Encrypts any data type by treating it as bytes
- `decrypt<V>(V& v, const char* key)` - Decrypts any data type

### Namespace: `array`

- `encrypt<V>(V& v, const char* key)` - Encrypts array data
- `decrypt<V>(V& v, const char* key)` - Decrypts array data

### Namespace: `str`

- `encrypt(std::string& st, const char* key)` - Encrypts std::string
- `decrypt(std::string& st, const char* key)` - Decrypts std::string
- `encrypt_char(char* st, const char* key)` - Encrypts C-string
- `decrypt_char(char* st, const char* key)` - Decrypts C-string

## How It Works

The library generates a numeric key by summing the ASCII values of all characters in the key string. This value is then added to (encryption) or subtracted from (decryption) each byte of the data, with modulo 256 to keep values in the byte range.

## Security Considerations

⚠️ **Important**: This library provides **basic obfuscation**, not cryptographic security. It should **NOT** be used for:

- Protecting sensitive data
- Secure communications
- Password storage
- Any security-critical applications

The encryption algorithm is:
- Easily reversible
- Vulnerable to frequency analysis
- Not resistant to known-plaintext attacks
- Provides no authentication or integrity checking

**Use cases**: Configuration file obfuscation, game save file protection, or basic data scrambling where security is not a concern.

## Requirements

- C++11 or later
- Standard C++ library

## License

[Specify your license here]

## Contributing

[Add contribution guidelines if applicable]

## Example Project

```cpp
#include "zero_size_encryption.h"
#include <iostream>
#include <string>

int main() {
    // Example with string
    std::string secret = "This is a secret message!";
    const char* key = "MySecretKey123";
    
    std::cout << "Original: " << secret << std::endl;
    
    ZeroSizeEncryptor::str::encrypt(secret, key);
    std::cout << "Encrypted: " << secret << std::endl;
    
    ZeroSizeEncryptor::str::decrypt(secret, key);
    std::cout << "Decrypted: " << secret << std::endl;
    
    return 0;
}
```