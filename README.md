# Simple SDL starter, with SDL and SDL modules included as Git submodules

# Build this project

1. Init and update the submodules 'git submodule init' and 'git submodule update'
2. Run 'cmake .. -DCMAKE_BUILD_TYPE=Debug'
3. Finally, run 'cmake --build . && cmake --install . --config Debug'
This will build the targets, install the build artefacts in the generated/ folder (DLLs)
4. generated/bin must be added to you OS Environment variables and the same goes for ThirdParties/DLLs where the .dll that are not generated can be found.
