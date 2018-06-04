<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>Operators - Plange</title>
		<link rel=StyleSheet href='../css/general.css' type='text/css' />
		<style>code { margin-left:20px; }</style>
	</head>
	<body>
		<?php 
		    require '../header.php';
		?>

		<p>Operators</p>
		<ul>
			<li><a href="https://en.wikipedia.org/wiki/Arity">arity</a></li>
			<li><a href="https://en.wikipedia.org/wiki/Operator_associativity">associativity</a></li>
			<li><a href="https://en.wikipedia.org/wiki/Operator_precedence">precedence</a></li>
			<li>result type - numeric, Boolean, enumerable, arbitrary</li>
			<li>operand types - numeric, Boolean, enumerable, arbitrary</li>
			<li>transitive, commutative, distributive, etc properties</li>
		</ul>
		<p>A categorical hierarchy is constructed for interpretation as <a href="/documentation/syntax.php">grammar rules</a>. Note that select symbols appear multiple times. These are interpreted in multiple possible ways. For example, - is both "negation" and "subtraction".</p>
        <p>NOTICE: This page is generated from the <a href="http://plange.tech/source/syntax.yml">syntax specification</a>. There are also operator-like elements that are not included here because of specialized syntax, such as <a href="http://plange.tech/documentation/syntax/DEFINITION.php">DEFINITION</a>.</p>
        
        <?php
            ini_set('display_errors', 1);
            ini_set('display_startup_errors', 1);
            error_reporting(E_ALL);
            
            $syntax_spec = yaml_parse_file('../source/syntax.yml');

            // Operator groups end with an '_OP' suffix.
            // Return true if the given name is an operator group
            function isOP($name) {
                $haystack = $name;
                $needle = "_OP";
                 return (substr($haystack, -strlen($needle)) === $needle) && $name !== "ASM_OP";
            }
            
            // Given an extended Wirth syntax string, return referenced entries.
            function extract_children($syntax) {
                $result = [];
                $tokens = explode(" ", $syntax);
                foreach ($tokens as $token) {
                    if (strlen($token) > 0) {
                        $isChild = true;
                        foreach (str_split($token) as $c) {
                            if (!ctype_alpha($c) && $c != "_") {
                                $isChild = false;
                                break;
                            }
                        }
                        if ($isChild) {
                            $result[] = $token;
                        }
                    }
                }
                return $result;
            }
            
            // Given an extended Wirth syntax string, return the string literals.
            function extract_string_literals($syntax) {
                $result = [];
                $pos = strpos($syntax, '"');
                while ($pos !== false) {
                    $start = $pos + 1;
                    $pos = strpos($syntax, '"', $start);
                    if ($pos === false) {
                        break;
                    }
                    $result[] = substr($syntax, $start, $pos - $start);
                    $pos = strpos($syntax, '"', $pos + 1);
                }
                return $result;
            }
        
            function process($indent, $name) {
                echo $indent . "<li>";
                echo $indent . "<a href=\"/documentation/syntax.php?name=" . $name . "\">" . $name . "</a>\n";
                global $syntax_spec;
                $syntax = trim($syntax_spec[$name]['syntax']);
                foreach (extract_string_literals($syntax) as $literal) {
                    echo "  " . $indent . "<code>";
                    echo $literal;
                    echo "</code> ";
                }
                if (isOP($name)) {
                    echo $indent . "<ul>\n";
                    $children = extract_children($syntax);
                    foreach ($children as $child) {
                        process("    " . $indent, $child);
                    }
                    echo $indent . "</ul>\n";
                }
                echo $indent . "</li>\n";
            }
            
            function process_OP_ASSIGNMENT() {
                echo "  <li><a href=\"/documentation/syntax.php?name=OP_ASSIGNMENT\">OP_ASSIGNMENT</a>\n";
                echo "    <ul>\n";
                global $syntax_spec;
                $syntax = trim($syntax_spec['OP_ASSIGNMENT']['syntax']);
                $children = extract_children($syntax);

                foreach ($children as $child) {
                    echo "      <li><a href=\"/documentation/syntax.php?name=" . $child . "\">" . $child . "</a>";
                    $childSyntax = trim($syntax_spec[$child]['syntax']);
                    $literals = extract_string_literals($childSyntax);                    
                    if (array_slice($literals, -2, 2) == ["<-", "←"]) {
                        array_splice($literals, -2);
                        foreach ($literals as $literal) {
                            echo " <code>";
                            echo $literal . "<-";
                            echo "</code> ";

                            echo " <code>";
                            echo $literal . "←";
                            echo "</code> ";
                        }
                    } else {
                        foreach ($literals as $literal) {
                            echo " <code>";
                            echo $literal;
                            echo "</code> ";
                        }
                    }
                    echo "</li>\n";
                }
                echo "    </ul>\n";
                echo "  </li>\n";
            }


            echo "<ul>\n";
            process("  ", "BINARY_OP");
            process("  ", "UNARY_OP");
            process_OP_ASSIGNMENT();
            echo "</ul>\n";
        ?>

		<?
		    php require('../footer.php')
		?>
	</body>
</html>
