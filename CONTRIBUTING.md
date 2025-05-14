# Contributing to PINAUK

Fork -> PR

All committed by you to this repository code's granted all rights to PINAUK-OS Team. Rights grant at the moment of PINAUK-OS Team approval of the Pull Request of yours.



## Coding standards

### File Structure & Naming

- Use snake case file naming (e.g., `snake_case.c`).
- Separate declarations (`.h`) and definitions (`.c`) clearly.
- Use include guards (`#ifndef ...`).
- Try to group related functions and types in dedicated files.

### Code Formatting

- Use one tab per indentation level.
- Limit lines to 80–120 characters.
- Use old-styled C :
  ```c
    if (condition) 
    {
        // do something
    }

	•	Add spaces around operators: x = a + b;
	•	Add a space after commas: foo(a, b, c);
	•	Use a blank line between blocks and functions.

### Naming Conventions
	•	Use snake_case for variables and functions.
	•	Use ALL_CAPS for macros and constants.
	•	Use PascalCase or prefixed names for structs, typedefs, and enums.
	•	Prefix global symbols to avoid name clashes (e.g., projname_funcname).

### Comments
	•	Use // for short comments, /* ... */ for block comments.
	•	Each file should begin with a brief description of its purpose.
	•	Comment each function with:
    ```c
        /**
         * FunctionName - Short description.
         * @param x: explanation
         * @return explanation
         */
    ```

	•	Use inline comments to explain non-obvious logic.

### Function Guidelines
	•	Keep functions under 50 lines if possible.
	•	Limit the number of parameters (ideally < 5).
	•	Always validate inputs.
	•	Use clear and consistent return value conventions (e.g., 0 for success).
	•	Use static for internal (file-local) functions.

### Error Handling
	•	Define clear return value meanings for functions.
	•	Use the kernel_panic function for returning errors. Document all codes on the project's Wiki. 

### Preprocessor & Macros
	•	Use ALL_CAPS for macro names.
	•	Avoid complex or side-effect macros.
	•	Prefer inline functions over macros where supported.
	•	Always wrap macro arguments in parentheses:
    ```c
        #define SQUARE(x) ((x) * (x))
    ```


### Types & Memory
	•	Use typedef struct { ... } Name; when appropriate.
	•	Prefer fixed-width types (int32_t, uint8_t) for portable code.
	•	Use explicit casting where needed.
	•	Always initialize pointers and check for NULL.

### Compiler & Portability
	•	Use #ifdef to isolate platform-specific code.
	•	Avoid compiler-specific extensions unless guarded and documented.

### Build System
	•	Document all required external libraries and tools.

### Testing
	•	Name test files consistently: test_module.c
	•	Write tests for each public API function.
    •   Always test the public API on real hardware.

### Documentation
	•	Document all public functions, types, and constants in the project's wiki.
	•	Keep README and build instructions up to date.
	•	Provide usage examples in comments or documentation files.

### Version Control
	•	Use clear, descriptive commit messages.
	•	Require reviews or testing before merging into main branches.
	•	Avoid committing generated files or local build artifacts. Add them to .gitignore.

### Sample Code Style
```c
#include <stdio.h>

#define MAX_COUNT 100

typedef struct {
    int id;
    char name[50];
} Item;

static void print_item(const Item *item) {
    printf("Item %d: %s\n", item->id, item->name);
}

int main(void) {
    Item item = {1, "Example"};
    print_item(&item);
    return 0;
}
```