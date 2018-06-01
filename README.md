
# Hello-World Postgresql extension

## Why ?

Just for fun ¯\\_(ツ)_/¯

Kind of Hello-World ;)

## What ?

Adding `pg_sleep(seconds)` and `pg_usleep(microseconds)` functions.

## Install

```
cd /usr/lib/postgresql/<version>/lib
git clone git@github.com:samber/pg_sleep.git
cd pg_sleep
make install
psql --command 'CREATE EXTENSION pg_sleep'
```

## Demo

```
$ docker-compose up -d
````

```
$ docker-compose exec bash

root@df76a9f0d69b:/# apt-get update
root@df76a9f0d69b:/# apt-get install gcc make libpq-dev postgresql-server-dev-all postgresql-contrib

root@df76a9f0d69b:/# cd /usr/lib/postgresql/10/lib/pg_sleep
root@df76a9f0d69b:/# make install
```

```
$ docker-compose exec psql -U postgres

psql (10.4 (Debian 10.4-2.pgdg90+1))
Type "help" for help.

postgres=# CREATE EXTENSION pg_sleep;
CREATE EXTENSION

postgres=# \timing
Timing is on.

postgres=# select pg_sleep(42);
 pg_sleep
----------
 t
(1 row)

Time: 42003.980 ms (00:42.004)
```
