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
        <p>Plange must provide all the same functionality at run time as it does at compile time. This facilitates self-modifying code, and makes it possible to endow an end-user with the capabilities of the developer. See the <a href="strongly-connected-model-of-computation.php">main page</a>.</p>

        <h2>Metaobjects</h2>
        <p>Introspection and meta-programming facilitate extensibility and DSLs.(see <a href="https://en.wikipedia.org/wiki/Metaobject">metaobject</a> on Wikipedia). See the <a href="metaobjects.php">metaobjects page</a>.</p>

        <h2>Verification</h2>
        A programming language has zero or more algebraic systems for the verification of programs. Haskell has types. Java has exception declarations. Rust has sound mutability. Prolog has predicate logic. Javascript has none at all. Languages are designed around the algebraic systems they leverage, if any, and appeasing these systems is required to produce a functional program. The effect is robustness, but a lack of flexibility and power. A language that offers many algebras and calculi, but doesn't mandate their use, is desirable. 
        
        <h2>Multi-Paradigm</h2>
        <p>Useful semantic features are included from each <a href="https://en.wikipedia.org/wiki/Programming_language_generations">generation of programming languages</a>.</p>
        <ul>
            <li>
                memory models
                <ul>
                    <li>garbage collection</li>
                    <li>heap</li>
                    <li>stack</li>
                    <li>automatic (deterministic when possible)</li>
                </ul>
            </li>
            <li>
                typing
                <ul>
                    <li>static type checking, dynamic objects with duck typing</li>
                    <li>strong, none</li>
                    <li>static binding, late binding</li>
                    <li>object-oriented</li>
                    <li>polymorphic</li>
                    <li>parametric (with covariance and contravariance)</li>
                    <li>algebraic (with pattern matching)</li>
                </ul>
            </li>
            <li>
                imperative
                <ul>
                    <li>procedural</li>
                    <li>object-oriented</li>
                </ul>
            </li>
            <li>declarative
                <ul>
                    <li>functional</li>
                    <li>algebraic</li>
                </ul>
            </li>
        </ul>

        <h2>Solver and C.A.S.</h2>
        <p>Constraints on systems, in the form of expressions in predicate logic, differentials, and other problem domains are solved symbolically, or numeric methods are used at runtime. The user may initiate symbolic evaluation within the IDE, especially for techniques that may have unbounded running time.</p>

        <h2>Scripting friendly</h2>
        <p>Simple problems should have simple solutions. The "Hello World" program must be one line of source code. As such, functions for printing, manipulating files, and other basic operations are automatically in scope of each translation unit. See the <a href="/documentation/standard-library.php">standard library</a>. Further, the barrier to entry must be low. Install once, configure by a gui, no package management</p>

        <h2>Bare Metal</h2>
        <p>The highest-level languages create an abstraction of the physical hardware that's dramatically different from the reality. This approach is very powerful. But as with all things, it is not the optimal solution for all problems. For high level abstractions, developers often (and sometimes unwittingly) exchange the ability to reach the "bare metal." Instead, a well-rounded language maintains the accessibility of the system hardware as a semantic feature of the language. The most obvious approach is to provide first-class inline assembler support. See: <a href="../documentation/keywords/asm.php">asm</a></p>
            
        <h2>Comprehensive Libraries, Documentation, Support</h2>
        <p>The "standard" libraries are modular and transparently retrieved from the plange.tech server when using the "import" keyword. The developer can also indicate which libraries should be compiled into the executable, making embedded systems and non-networked applications possible. Third-party libraries are accessed by providing a URL to the import keyword. Documentation will (in part) be generated from docstrings within the source code. Plange.tech will have a user forum, and premium support should be available.</p>

        <h2>Communicate Well</h2>
        <p>Documentation is exhaustive, generated whenever possible, and available wherever possible. This website serves as the primary source for structured and unstructured information used in the building of the tool chain.</p>

        <p>Error message, diagnostics, etc. should be helpful. e.g. Think of clang's template error messages versus gcc's.</p>

        <?php require('../footer.php') ?>
    </body>
</html>