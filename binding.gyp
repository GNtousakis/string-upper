{
  "targets": [
    {
      "target_name": "UpperCaseString",
      "sources": [ "/src/UpperCaseString.cpp" ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}
