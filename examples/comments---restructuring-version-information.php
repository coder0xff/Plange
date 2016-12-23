<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>~EXTRA COMMENTS - Restructuring Version Information - Plange</title>
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

/* and creates a tree, such as this: 

    o                       result object
    |
    |---0
    |   |---5               version 0.5
    |  
    |---1
    |   |---0               version 1.0
    |   |---1               version 1.1
    |
    |---2
        |---0               version 2.0

*/

// The structure of the result object
Result_t := Map&lt;Int, Set&lt;Int&gt;&gt;;

&lt;Result_t&gt; expected := { 0: {|5|}, 1: {|0,1|}, 2: {|0|} };

// A signature for a tail recursive function that builds the result:
Recursive_function_t := Result_t * List&lt;Int * Int&gt; → Result_t;

// The algorithm
&lt;Recursive_function_t&gt; listToTree :=
    // Below is the first function overload, the main logic.
    // The first parameter is the intermediate state of the result tree as it is built.
    // In the second parameter, the constants 'major' and 'minor' refer to the elements of a tuple;
    // specifically, the tuple that is the list head (to the left of the ':').
    // To the right side of the ':', 'tail' for the rest of the list.
    // The new computed state, is passed to this function recursively.
    // Each recursion represents a step through the list, and a new leaf on the tree.
    (state, (|major, minor|)&tail) {

        //Get the set 's', based on the major version.
        //If the map doesn't have a corresponding key, it uses the second argument.
        //That key-value pair becomes a new part of the result state
        &lt;Set&lt;Int&gt;&gt; s := state.get_or_add(major, Set&lt;Int&gt;());
        
        //Add the 'minor' value to the set.
        //If it's already there, then no change is made.
        s.add(minor);

        //use tail recursion to go to the next element
        return listToTree(state, tail);
    } | //the pipe character creates overloaded functions

    //handle the terminal case - no more items
    (state, []) { return state; } |

    // The last overload, a helper function that instantiates the initial result object
    (&lt;List&lt;Int * Int&gt;&gt; version_pairs) {
        return listToTree({}, version_pairs);
    };

assert(listToTree(input) = expected);</pre>
        </div>


		<?php require('../footer.php') ?>
	</body>
</html>