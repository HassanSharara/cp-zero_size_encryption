#pragma once

#include "pch.h"
#include <stdint.h>
#include <string>
namespace ZeroSizeEncryptor {


	template <typename L>
	inline L generate_key_results(const char* key) {
		L results = 0;
		for (char const* p = key; *p != '\0'; p++) results += (uint8_t)*p;
		return results;
	}



	template <typename L>
	void encrypt(uint8_t* bytes, L length, const char* key) {
		L key_results = generate_key_results<L>(key);
		for (L i = 0; i < length; i++)bytes[i] = (bytes[i] + key_results) % 256;
	}

	template <typename L>
	void decrypt(uint8_t* bytes, L length, const char* key) {
		L key_results = generate_key_results<L>(key);
		for (L i = 0; i < length; i++)bytes[i] = (bytes[i] - key_results) % 256;
	}






	namespace any {

		template<typename V>
		void encrypt(V& v, const char* key) {
			size_t len = sizeof(v);
			uint8_t* pointer = reinterpret_cast<uint8_t*>(&v);
			ZeroSizeEncryptor::encrypt(pointer, len, key);
		}
		template<typename V>
		void decrypt(V& v, const char* key) {
			size_t len = sizeof(v);
			uint8_t* pointer = reinterpret_cast<uint8_t*>(&v);
			ZeroSizeEncryptor::decrypt(pointer, len, key);
		}
	}

	namespace array {

		template<typename V>
		void encrypt(V& v, const char* key) {
			size_t len = sizeof(v);
			uint8_t* pointer = (uint8_t*)v;
			ZeroSizeEncryptor::encrypt(pointer, len, key);
		}
		template<typename V>
		void decrypt(V& v, const char* key) {
			size_t len = sizeof(v);
			uint8_t* pointer = (uint8_t*)v;
			ZeroSizeEncryptor::decrypt(pointer, len, key);
		}
	}
	namespace str {

		void encrypt_char(char* st, const char* key) {
			int key_results = generate_key_results<int>(key);
			for (char* p = st; *p != '\0'; p++)*(uint8_t*)p = ((uint8_t)*p + key_results) % 256;
		}


		void decrypt_char(char* st, const char* key) {
			int key_results = generate_key_results<int>(key);
			for (char* p = st; *p != '\0'; p++)*(uint8_t*)p = ((uint8_t)*p - key_results) % 256;
		}
		void encrypt(std::string& st, const char* key) {
			char* first_byte = (char*)st.data();
			encrypt_char(first_byte, key);
		}
		void decrypt(std::string& st, const char* key) {
			char* first_byte = (char*)st.data();
			decrypt_char(first_byte, key);
		}
		
	};
};