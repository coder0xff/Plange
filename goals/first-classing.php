<meta charset='utf-8'/>
<html>
	<head>
		<title></title>
		<link rel=StyleSheet href='../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../header.php') ?>


		<p>It is increasingly common for languages to treat programming concepts as “first class.” For example, <a href="https://en.wikipedia.org/wiki/Reflection_%28computer_programming%29">reflection</a> in Java and C# is a solution for making types first class. A type is not a black box, hard coded by a programmer that is only used to create objects. It is a value that can be inspected and manipulated. Functions are also commonly first class, in that they can be assigned to variables, constructed at run time, and be subjected to lambda calculus.</p>
		
		<p>The process of first classing can be described as such:</p>
		<p><b>The abstraction of language features into representations that may be constructed, inspected, and manipulated by that same language.</b></p>
		<p>The result of first classing is a development environment in which the</p>
		<ul>
			<li>objects</li>
			<li>functions</li>
			<li>logic</li>
			<li>architecture</li>
			<li>documentation, and</li>
			<li>binaries</li>
		</ul>
		<p>of the</p>
		<ul>
			<li>toolchain</li>
			<li>runtime</li>
			<li>programs</li>
			<li>debugger</li>
			<li>editor, and</li>
			<li>IDE</li>
		</ul>
		<p>can be</p>
		<ul>
			<li>constructed</li>
			<li>inspected, and</li>
			<li>manipulated</li>
		</ul>
		<p>by programs.</p>
		<p>There are APIs for each of the items in the following (incomplete) table. The code tier, and the documentation feature (in the software tier), is also accessible through syntax.</p>
		<table border="1" bordercolor="#888" cellspacing="0" style="border-collapse:collapse;border-color:rgb(136,136,136);border-width:1px" width="600">
			<colgroup>
				<col width="*">
				<col width="*">
				<col width="*">
			</colgroup>
			<tbody>
				<tr>
					<td><b>Code Tier</b></td>
					<td><b>Software Tier</b></td>
					<td><b>Build Tier</b></td>
				</tr>
				<tr>
					<td>types</td>
					<td>modules</td>
					<td>compilation</td>
				</tr>
				<tr>
					<td>functions</td>
					<td>libraries</td>
					<td>profiling</td>
				</tr>
				<tr>
					<td>syntax trees</td>
					<td>programs</td>
					<td>optimization</td>
				</tr>
				<tr>
					<td>constraints</td>
					<td>extensions</td>
					<td>language grammar(s)</td>
				</tr>
				<tr>
					<td>execution contexts</td>
					<td>certificates</td>
					<td>runtimes</td>
				</tr>
				<tr>
					<td>side effects</td>
					<td>processes</td>
					<td>toolchain</td>
				</tr>
				<tr>
					<td>expressions</td>
					<td>permissions</td>
					<td>IDE</td>
				</tr>
				<tr>
					<td>statements</td>
					<td>documentation</td>
					<td>dependency graphs</td>
				</tr>
			</tbody>
		</table>
		<p>See also: <a href="/goals/strongly-connected-model-of-computation">Strongly Connected Model Of Computation</a></p>


		<?php require('../footer.php') ?>
	</body>
</html>