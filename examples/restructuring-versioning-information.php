<meta charset='utf-8'/>
<html>
	<head>
		<title>Restructuring Versioning Information - Plange</title>
		<link rel=StyleSheet href='/css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('/header.php') ?>


style="margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
        <p style="font-size:12pt;margin:0px;padding-left:6pt;background-color:#cda">
            restructuring.plg
        </p>
        <pre style="margin:0px;padding:3px;font-family:Courier New;width:715px;max-height:500px;overflow-x:auto;overflow-y:auto">
            ///////////////////////////////////////////////////////////////////////////
// This code, written in Plange (which is a work in progress),
// presents a commented implementation of an algorithm
// for manipulating data structures representing the
// "version numbers" of software. The algorithm takes
// a list of version pairs (tuples 'int * int', for major and
// minor respectively):

input = [ // start a list
    (0,5),    // version 0.5
    (1,0),    // version 1.0
    (1,1),    // version 1.1
    (2,0)     // version 2.0
];        // finish the list

expected = { 0:{5}, 1:{0,1}, 2:{0} };

// The structure of the result object - the tree above:
Result_t = Map&lt;Int, Set&lt;Int&gt;&gt;;

// A signature for a tail recursive function that builds the result:
Recursive_function_t = Result_t, List&lt;Int * Int&gt; -&gt; Result_t;

// The algorithm
&lt;Recursive_function_t&gt; listToTree =
    (state, ((major, minor):tail) {
        &lt;Set&lt;Int&gt;&gt; s = state.get_or_add(major, Set&lt;Int&gt;());
        s.add(minor);
        return listToTree(state, tail);
    } |

    (state, []) { return state; } |

    (List&lt;Int * Int&gt; version_pairs) {
        return listToTree({}, version_pairs);
    };
    
assert(listToTree(input) = expected);
        </pre>
    </div>



		<?php require('/footer.php') ?>
	</body>
</html>