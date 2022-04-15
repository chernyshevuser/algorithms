#include "strings/packed_prefix/strings_packed_prefix.h"
#include "strings/packed_prefix/strings_packed_prefix_test.h"

#include "strings/crib/strings_crib.h"
#include "strings/crib/strings_crib_test.h"

int main() {
    strings_packed_prefix::TestAll();
    strings_packed_prefix::RunProgram();

    strings_crib::TestAll();
    strings_crib::RunProgram();

}