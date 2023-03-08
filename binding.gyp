{
    "targets": [{
        "target_name": "JSONSki",
        "cflags!": [ "-fno-exceptions" ],
        "cflags_cc!": [ "-fno-exceptions" ],
        "sources": [
            "src/bindings.cpp",
             "main.cpp",
             "src/RecordLoader.cpp",
             "src/QueryProcessor.cpp",
             "src/JSONPathParser.cpp"

        ],
      "cflags": [
         # Here all your CFLAGS
       ],
       "cflags_cc": [
    
       # Here all your C ++ FLAGS
       ],
           "xcode_settings": {
        "OTHER_CFLAGS": ["-O3", "-std=c++11", "-msse","-msse3", "-msse2", "-msse4", "-msse4.1", "-mpclmul", "-lpthread", "-march=native"],
        "GCC_ENABLE_CPP_EXCEPTIONS": "YES"
      },
        'include_dirs': [
            "<!@(node -p \"require('node-addon-api').include\")"
        ],
        'libraries': [],
        'dependencies': [
            "<!(node -p \"require('node-addon-api').gyp\")"
        ],
        'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ]
    }]
}