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
Result_t := Map<Int, Set<Int>>;

<Result_t> expected := { 0: {|5|}, 1: {|0,1|}, 2: {|0|} };

// A signature for a tail recursive function that builds the result:
Recursive_function_t := Result_t * List<Int * Int> → Result_t;

// The algorithm
<Recursive_function_t> listToTree :=
    (state, (|major, minor|)&tail) {
        <Set<Int>> s := state.get_or_add(major, Set<Int>());
        s.add(minor);
        return listToTree(state, tail);
    } |

    (state, []) { return state; } |

    (<List<Int * Int>> version_pairs) {
        return listToTree({}, version_pairs);
    };

assert(listToTree(input) = expected);</pre>
        </div>



		<?php require('../footer.php') ?>
	</body>
</html>