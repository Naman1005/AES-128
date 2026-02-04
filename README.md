
# AES‑128 Command‑Line Tool (C++)

**Short description**  
`aes_cli` is a compact, self-contained AES‑128 implementation and command‑line utility written in modern C++. It provides file‑level AES encryption and decryption using a 16‑byte (128‑bit) key. This project is intended for learning, experimentation, and small internal tools.

---

## Features
- AES‑128 encrypt/decrypt for arbitrary binary files.
- Minimal dependencies (single header/source layout).
- Simple, POSIX‑friendly build and run flow (g++).
- Example sample files included (`sample.txt`, `decrypted.txt`).

---

## Quick start

### Build (Linux / macOS)
Requires `g++` supporting C++11.

```bash
# quick build using provided script
bash build.sh

# or compile manually
g++ -std=c++11 -Wall -Iinclude main.cpp src/aes.cpp src/file_utils.cpp -o aes_cli
```

`build.sh` compiles the binary `aes_cli` in the repository root.

### Usage
```
./aes_cli <encrypt|decrypt> <input_file> <output_file> <key(16 chars)>
```

**Examples**
```bash
# Encrypt plain text -> encrypted binary
./aes_cli encrypt sample.txt encrypted.bin "16byteSecretKey!"

# Decrypt back to original
./aes_cli decrypt encrypted.bin decrypted.txt "16byteSecretKey!"
```

Notes:
- The key **must be exactly 16 characters** (16 bytes / 128 bits). The CLI will parse the key string directly into bytes.
- Input and output are handled as binary blobs - you can encrypt text or arbitrary binary files.

---

## Repository layout
```
.
├── aes_cli                # (built executable after compile)
├── build.sh               # simple build script
├── decrypted.txt          # example decrypted output
├── encrypted.bin          # (not included) suggested output name for encrypted data
├── include/
│   ├── aes.h              # AES128 class interface
│   └── file_utils.h       # small file helpers
├── main.cpp               # CLI argument parsing + glue
├── sample.txt             # sample plaintext
├── src/
│   ├── aes.cpp            # AES implementation (S-box, rounds, key expansion)
│   └── file_utils.cpp     # read/write helpers
├── .gitignore
```

---

## Implementation notes & caveats
- The AES implementation is a pedagogical / educational style implementation. It demonstrates S‑box, ShiftRows, MixColumns, key expansion, and typical AES round functions.
- **Not constant‑time**: This implementation has not been hardened against timing attacks. Do **not** use as-is for cryptographic production systems.
- For production, prefer well‑maintained libraries like OpenSSL, libsodium, or platform cryptography APIs that implement authenticated encryption (e.g., AES‑GCM) and key management.
- No authentication/integrity: This tool only provides confidentiality (encryption). There is no message authentication (HMAC or AEAD). To avoid undetected tampering, wrap encryption with an authenticated mode or add an HMAC.

---

## Testing the included sample
1. Build the project (see above).
2. Run encryption:
```bash
./aes_cli encrypt sample.txt encrypted.bin "16byteSecretKey!"
```
3. Run decryption:
```bash
./aes_cli decrypt encrypted.bin decrypted.txt "16byteSecretKey!"
```
4. Verify `decrypted.txt` equals `sample.txt`.
