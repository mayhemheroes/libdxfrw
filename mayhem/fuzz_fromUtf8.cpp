#include <stdint.h>
#include <stdio.h>
#include <climits>

#include <fuzzer/FuzzedDataProvider.h>
#include "drw_textcodec.h"

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    FuzzedDataProvider provider(data, size);
    DRW_TextCodec drw_textcodec;

    drw_textcodec.fromUtf8(provider.ConsumeRandomLengthString(1000));

    return 0;
}
