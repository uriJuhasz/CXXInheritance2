import qbs

Project {
    minimumQbsVersion: "1.7.1"

    qbs.architecture: ["x86_64"]
    qbs.targetOS:     ["windows"]

    CppApplication {
        name: "CXXInheritance2"
        targetName: name + ".exe"
        consoleApplication: true
        files: "main.cpp"

        cpp.systemIncludePaths: [ "/msys64/mingw64/include/c++/7.2.0"
                                 ,"/msys64/mingw64/include/c++/7.2.0/x86_64-w64-mingw32"
                                 ,"/msys64/mingw64/include/c++/7.2.0/backward"
                                 ,"/msys64/mingw64/lib/clang/5.0.0/include"
                                 ,"/msys64/mingw64/x86_64-w64-mingw32/include"
                                 ,"/msys64/mingw64/include"
                           ]
        cpp.cxxFlags: [
                        "-pedantic", "-Wall", "-Wextra"
                       ,"-std=c++17"
//                     ,"-v"
                       ,"--target=x86_64-w64-windows-gnu"
                      ]

        cpp.positionIndependentCode: false

        Group {     // Properties for the produced executable
            fileTagsFilter: product.type
            qbs.install: true
        }
    }
}
