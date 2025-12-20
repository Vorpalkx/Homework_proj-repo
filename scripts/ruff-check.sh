#!/bin/bash

ruff format .
ruff check --fix .
ruff check --statistics .
