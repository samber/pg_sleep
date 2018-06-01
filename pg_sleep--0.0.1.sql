-- complain if script is sourced in psql, rather than via CREATE EXTENSION
\echo Use "CREATE EXTENSION pg_sleep" to load this file. \quit

CREATE FUNCTION pg_sleep(integer) RETURNS boolean
    AS '$libdir/pg_sleep', 'pg_ext_sleep'
    LANGUAGE C IMMUTABLE;

CREATE FUNCTION pg_usleep(integer) RETURNS boolean
    AS '$libdir/pg_sleep', 'pg_ext_usleep'
    LANGUAGE C IMMUTABLE;
