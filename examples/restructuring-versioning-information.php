<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>Restructuring Versioning Information - Plange</title>
		<link rel=StyleSheet href='../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../header.php') ?>



        <div class="code">
            <p>restructuring.pge</p>
            <pre>///////////////////////////////////////////////////////////////////////////
// This code, written in Plange (which is a work in progress),
// presents a commented implementation of an algorithm
// for manipulating data structures representing the
// "version numbers" of software. The algorithm takes
// a array of version pairs (tuples 'int * int', for major and
// minor respectively):

input := [ // start an array
    (| 0, 5 |), // tuple for version 0.5
    (| 1, 0 |), // version 1.0
    (| 1, 1 |), // version 1.1
    (| 2, 0 |)  // version 2.0
];         // finish the array

// The structure of the result object
Result_t := Map&lt;Int, Set&lt;Int&gt;&gt;;

&lt;Result_t&gt; expected := { 0: {|5|}, 1: {|0,1|}, 2: {|0|} };

// A signature for a tail recursive function that builds the result:
Recursive_function_t := Result_t * List&lt;Int * Int&gt; → Result_t;

// The algorithm
&lt;Recursive_function_t&gt; listToTree :=
    (state, (|major, minor|)&tail) {
        &lt;Set&lt;Int&gt;&gt; s := state.get_or_add(major, Set&lt;Int&gt;());
        s.add(minor);
        return listToTree(state, tail);
    } |

    (state, []) { return state; } |

    (&lt;List&lt;Int * Int&gt;&gt; version_pairs) {
        return listToTree({}, version_pairs);
    };

assert(listToTree(input) = expected);</pre>
        </div>



		<?php require('../footer.php') ?>
	</body>
</html>