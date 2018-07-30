# Exprerimental
## メモリコピー速度計測
### VC用
- ソース memcpy_vc.cpp
- コンパイル cl /Ox memcpy_vc.cpp
- 結果 11.2GB/s

### WSL用
- ソース memcpy_wsl.cpp
- コンパイル　g++ -o memcpy_wsl -O3 mem_wsl.cpp
- 結果 9.7GB/s
