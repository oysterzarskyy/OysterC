# OysterC Language Specification

## Overview
OysterC is a hybrid programming language for scripting, native tooling, and Android application development. It combines a clean, beginner-friendly syntax with a compiler pipeline that can emit C-compatible code and work with Gradle-based Android builds.

## Goals
- Easy for beginners to read and write
- Suitable for shell automation and system scripts
- Compatible with C primitives and existing C libraries
- Supports Android app development through Gradle
- Provides concurrency, modules, exceptions, and classes

## Syntax
- Statements end with newline or semicolon
- Blocks use indentation or braces
- Variables use `let` and `const`
- Functions use `fun`
- Classes use `class`
- Modules use `module`

## Core Types
- `int`, `float`, `bool`, `string`, `list`, `map`, `null`, `any`
- Optional types use `?`

## Features
- Variables and type inference
- Functions with default parameters
- Classes with methods and constructors
- Modules and imports
- Exceptions with `try/catch/finally`
- Concurrency with `spawn`
- Interop with Bash via `bash { ... }`
- Interop with C via `extern "C"`

## Runtime Model
- Heap-managed objects with reference counting
- Native bindings for C libraries
- Gradle plugin produces APK and AAR artifacts

## Tooling
- `oysterc build` compiles source to C or native output
- `oysterc run` executes a source file
- `oysterc android init` creates an Android project skeleton
