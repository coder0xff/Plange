<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
    <head>
        <title>Goals - Plange</title>
        <link rel=StyleSheet href='../css/general.css' type='text/css' />
    </head>
    <body>
        <?php require('../header.php') ?>

        <big>The fundamental challenge:</big>
        <div style="padding:24pt">
            <big>
                <big>
                    <big>
                       Enable developers to do whatever they conceive.
                    </big>
                </big>
            </big>
        </div>

        <p>Plange may not accomplish a developers goals for them, but it strives to stay out of the way while maintaining its usefulness. In other words: do not obstruct any use case, and anticipate many of them. As the developer explores the languages capabilities, they discover new potential domains rather than boundaries. A small number of specific goals stem from this notion, and provide an outline for the project.</p>

        <h2>Strongly-Connected Model Of Computation</h2>
        <p>Plange must provide all the same functionality at run time as it does at compile time, including mutability. The theoretical result is that all computation, including compilation, is a form of constant folding. As much is done in advance as possible, but compiling and optimizing can be done at runtime as well. Features can be culled from executable modules to reduce their size. Given that internet access is provided, executables may even download missing Plange modules as required.
        <a href="strongly-connected-model-of-computation.php">main page</a>.</p>

        <h2>Metaobjects</h2>
        <p>Introspection and meta programming turn code into data, and facilitate extensibility.(see <a href="https://en.wikipedia.org/wiki/Metaobject">metaobject</a> on Wikipedia). See the <a href="metaobjects.php">main page</a>. Combined with the strongly-connected model of computation, even metaobjects have metaobjects. Programs and entire logical or physical systems can become dynamic objects.</p>

        <h2>Multi-Paradigm</h2>
        <p>Semantic features are included from each <a href="https://en.wikipedia.org/wiki/Programming_language_generations">generation of programming language, and multiple type-system styles are featured</a>.</p>
        <ul>
            <li>
                Memory models
                <ul>
                    <li>
                        garbage collection
                    </li>
                    <li>
                        heap
                    </li>
                    <li>
                        stack
                    </li>
                    <li>
                        automatic (deterministic when possible)
                    </li>
                </ul>
            </li>
            <li>
                Typing
                <ul>
                    <li>
                        static type checking, dynamic objects with duck typing
                    </li>
                    <li>
                        strong, none
                    </li>
                    <li>
                            static binding, late binding
                    </li>
                    <li>
                            object-oriented
                    </li>
                    <li>
                            polymorphic
                    </li>
                    <li>
                            parametric (with covariance and contravariance)
                    </li>
                    <li>
                            algebraic (with pattern matching)
                    </li>
                </ul>
            </li>
        </ul>

        <h2>Solver and C.A.S.</h2>
        <p>The interface to the solver and computer algebra system is through syntax and semantics built into the language. Constraints on systems, in the form of expressions in predicate logic, differentials, and other problem domains are solved symbolically, or numeric methods are used at runtime.</p>

        <h2>Scripting friendly</h2>
        <p>Ensure that simple solutions exist for simple problems. The "Hello World" program must be one line of source code, one statement. As such, functions for printing, manipulating files, and other basic operations are automatically in scope of each translation unit. See the <a href="/documentation/standard-library.php">standard library</a>. Further, the bar to entry must be low for provisioning and for typical use. Accessibility is critical to good adoption.</p>

        <h2>Bare Metal</h2>
        <p>The highest level languages create an abstraction of the physical hardware that's dramatically different from the reality. This approach is very powerful. But as with all things, it is not the optimal solution for all problems. For high level abstractions, developers often (and sometimes unwittingly) exchange the ability to reach the "bare metal." Instead, a well rounded language maintains the accessibility of the system hardware as a semantic feature of the language. The most obvious approach is to provide first-class inline assembler support. See: <a href="../documentation/keywords/asm.php">asm</a></p>
            
        <h2>Comprehensive Libraries, Documentation, Support</h2>
        <p>A standard library that is broad, compared to python, or .Net. This website (plange.tech) catalogs the requirements of the project, and provides a moderated platform for open-source user contributions.</p>

        <h2>Communicate Well</h2>
        <p>Documentation is exhaustive, generated wherever possible, and available whenever possible. This website serves as the primary source for structured and unstructured information used in the building of the tool chain. For example, the Syntax pages (under Documentation) of this website are used by a web scraper to generate grammar files plange. Formalism in documentation and source code is highly valued.</p>

        <p>Error message, diagnostics, etc. should be helpful. e.g. Think of clang's template error messages versus gcc's.</p>        

        <?php require('../footer.php') ?>
    </body>
</html>