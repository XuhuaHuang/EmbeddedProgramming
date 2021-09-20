# Introduction

---

## 2.1 Java Virtual Machine
* All Java code written runs on JVM (core of the language)
* JVM runs on various operating system
* Think of it as a cross-platform compiler/translator

## 2.2 JRE and JDK
1. JRE - Java Runtime Environment (includes JVM and other libraries)
2. JDK - Java Development Kit (includes JRE and other development tools)

## 2.3 System Environment Variables
1. Right click on `This PC`, check out `Advanced\Environment Variables`
2. Under `System Variables`, click `New..`
3. Enter `JAVA_HOME` for variable name, and path to JDK for value,
   e.g. `C:\Program Files\Java\jdk-9.0.4`
4. Change the `Path` variable: Add `%JAVA_HOME%\bin`
5. Note: `%JAVA_HOME%` is macro is replaced with the defined path in step 3
   Equivalent: `C:\Program Files\Java\jdk-9.0.4\bin`

---

## 3.1 Hello World
1. Write source code in a source code: *.java files
2. Compiler takes `.java` and compile into `.class` (Java bytecode file)
3. Finally, JVM runs the bytecode file
4. All changes made to the source file requires compiling

source code:
```Java
/* HelloWorld.java */
/* HelloWorld matches the filename without the .java extension */
public class HelloWorld {
  public static void main(String[] args) {
    System.out.println('Hello, world!');
  }
}
```

to compile:
```bash
$ javac HelloWorld.java # generates a `HelloWorld.class` Java bytecode file
$ java HelloWorld
```

## 3.2 Keyword Summary
* All lower case words (public, private)
* Indexed special colours

## 3.3 Naming Conventions
* Can not start with numbers [0-9]
* Can not be java keywords
* For class naming, use chemo casing with capital letters: `MyClass`
* For variable and method naming: `myVar` and `myMethod`

---

## 4.1 Constant Variables
* Definition: variables that are not going to change while executing
* Types of constants in Java:
  * String
  * Integer
  * Float
  * Double
  * Character
  * Boolean
  * null

Source code:
```Java
/* DemoConst.java */
public class DemoConst {
  public static void main(Stirng[] args) {
    /* String */
    System.out.println("ABC");
    System.out.println(""); // prints an empty line
    System.out.println("XYZ");
    /* Integer */
    System.out.println(30);

    /* Float */
    System.out.println(3.1416);

    /* Character */
    System.out.println('A'); // only one character with a pair of single quotes

    /* Boolean */
    System.out.println(true);
    System.out.println(false);
  }
}
```

---

## 5.1 Primitive Data Types
* byte, short, int, long
* float, double
* char
* Boolean

### Important:
* String is **not** a primitive data type
* Range is not necessarily related to bit counts of the object:
  float(4 bits) has a wider range than long(8 bits)
* Float defaults to double; use a trailing `f` to force it to be float
* Integer defaults to int; use a trailing `l` to force it to be long

---
