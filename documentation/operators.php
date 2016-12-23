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

		<p>The following properties may be used to categorize operators</p>
		<ul>
			<li><a href="https://en.wikipedia.org/wiki/Arity">arity</a></li>
			<li><a href="https://en.wikipedia.org/wiki/Operator_associativity">associativity</a></li>
			<li><a href="https://en.wikipedia.org/wiki/Operator_precedence">precedence</a></li>
			<li>result type - numeric, Boolean, enumerable, arbitrary</li>
			<li>operand types - numeric, Boolean, enumerable, arbitrary</li>
			<li>transitive, commutative, distributive, etc properties</li>
		</ul>
		<p>A categorical hierarchy is constructed for interpretation as <a href="/documentation/syntax.php">grammar rules</a>. Note that select symbols appear multiple times. These are interpreted in multiple possible ways. For example, - is both "negation" and "subtraction".</p>
        <p>NOTICE: This page is generated from the <a href="http://plange.tech/source/syntax.yml">syntax specification</a>.</p>
        
        <?php
            ini_set('display_errors', 1);
            ini_set('display_startup_errors', 1);
            error_reporting(E_ALL);
            
            require_once "../Spyc.php";

            $syntax_spec = spyc_load_file('../source/syntax.yml');

            function isOP($name) {
                $haystack = $name;
                $needle = "_OP";
                $length = strlen($needle);
                if ($length == 0) {
                    return true;
                }
            
                return (substr($haystack, -$length) === $needle) && $name !== "ASM_OP";
            }
            
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
        
            function build_tree($name) {
                global $syntax_spec;
                if (isOP($name)) {
                    $production = str_replace(" ", "", $syntax_spec[$name]["syntax"]);
                    $children = explode("|", $production);
                    $result = [];
                    foreach ($children as $child) {
                        $result[$child] = build_tree($child);
                    }
                    return $result;
                } else {
                    return extract_string_literals($syntax_spec[$name]["syntax"]);
                }
            }

            $tree = [
                "DEFINITION" => [":="],
                "ASSIGNMENT" => ["<-", "←"],
                "CONDITIONAL" => ["? :"],
                "DIMENSIONAL_ANALYSIS_OP" => build_tree("DIMENSIONAL_ANALYSIS_OP"),
                "BINARY_OP" => build_tree("BINARY_OP"),
                "UNARY_OP" => build_tree("UNARY_OP")
            ];

            //echo "<pre>";
            //print_r($tree);
            //echo "</pre>";
            
            function codify($text) { return "<code>" . $text . "</code>"; }

            function build_html($subtree, $indent) {
                foreach ($subtree as $name => $def) {
                    echo "<tr><td>";
                    echo str_repeat("&nbsp;", $indent * 8);
                    echo "<a href='/documentation/syntax/" . $name . ".php'>" . strtolower($name) . "</a>";
                    if (isOP($name)) {
                        echo "</td></tr>";
                        build_html($def, $indent + 1);
                    } else {
                        echo "</td><td>";
                        echo implode("&nbsp;,&nbsp;", array_map('codify', $def));
                        echo "</td></tr>";
                    }
                }
            }
            
            echo "<table>";
            build_html($tree, 0);
            echo "</table>";
        ?>

		<?
		    php require('../footer.php')
		?>
	</body>
</html>
