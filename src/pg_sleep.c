
#include <unistd.h>

#include "postgres.h"
#include "fmgr.h"
#include "utils/builtins.h"

#ifdef PG_MODULE_MAGIC
PG_MODULE_MAGIC;
#endif

PG_FUNCTION_INFO_V1(pg_ext_sleep);
PG_FUNCTION_INFO_V1(pg_ext_usleep);

Datum pg_ext_sleep(PG_FUNCTION_ARGS)
{
    int t = PG_GETARG_INT32(0);

    if (t < 0)
        ereport(ERROR,
                (
                    errcode(ERRCODE_NUMERIC_VALUE_OUT_OF_RANGE),
                    errmsg("negative values are not allowed"),
                    errdetail("value %d is negative", t),
                    errhint("make it positive")));

    sleep((unsigned int)t);
    PG_RETURN_BOOL(true);
}

Datum pg_ext_usleep(PG_FUNCTION_ARGS)
{
    int t = PG_GETARG_INT32(0);

    if (t < 0)
        ereport(ERROR,
                (
                    errcode(ERRCODE_NUMERIC_VALUE_OUT_OF_RANGE),
                    errmsg("negative values are not allowed"),
                    errdetail("value %d is negative", t),
                    errhint("make it positive")));

    usleep((unsigned int)t);
    PG_RETURN_BOOL(true);
}
