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
                        Create a development environment that permits
                the developer to do whatever they conceive.
                    </big>
                </big>
            </big>
        </div>

        <p>Plange may not accomplish a developers goals for them, but it strives to stay out of the way while maintaining its usefulness. In other words: do not obstruct any use case, and anticipate many of them. As the developer explores the languages capabilities, they discover new potential domains rather than boundaries. A small number of specific goals stem from this notion, and provide an outline for the project.</p>

        <h2>Strongly-Connected Model of Computation</h2>
        <p>A key concept for maximizing power and flexibility, and proof that
        plange does not obstruct any use case. See the
        <a href="strongly-connected-model-of-computation.php">main page</a>.</p>

        <h2>Metaobjects</h2>
        <p>An approach to meta programming (see <a href="https://en.wikipedia.org/wiki/Metaobject">metaobject</a> on Wikipedia). See the <a href="metaobjects.php">main page</a>.</p>

        <h2>Multi-Paradigm</h2>
        <p>Support semantics from each <a href="https://en.wikipedia.org/wiki/Programming_language_generations">generation of programming language</a>.</p>
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
                        static, dynamic
                    </li>
                    <li>
                        strong, weak
                    </li>
                    <li>
                        <span>
                            late binding/duck typing
                        </span>
                    </li>
                    <li>
                        <span>
                            object-oriented
                        </span>
                    </li>
                    <li>
                        <span>
                            polymorphic
                        </span>
                    </li>
                    <li>
                        <span>
                            parametric (with covariance and contravariance)
                        </span>
                    </li>
                    <li>
                        <span>
                            algebraic (with pattern matching)
                        </span>
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