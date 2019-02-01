<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>Computer Algebra - Plange</title>
		<link rel=StyleSheet href='../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../header.php') ?>
		
		<p>Solvers are very limited. Numeric methods also require domain knowledge. Each algebra operates on expressions within its normal form. Normalization is left to the programmer except in specific supported cases. Some algebras have bounded execution times, such as Risch integration. In general, an algebra may offer no such guarantees.</p>

		<h4>Example</h4>

		<p>One well studied domain is <a href="https://en.wikipedia.org/wiki/Initial_value_problem">initial value problems</a>. An ordinary differential equation is given with boundary conditions on free variables:</p>

		<div class="code2">
			<p>Example: Aerodynamic Drag On A Projectile</p>
			<pre>
projectilePosition := (
		&lt;Vector3D&gt; initialPos,
		&lt;Vector3D&gt; initialVel,
		&lt;Real&gt; mass,
		&lt;Real&gt; drag,
		&lt;Vector3D&gt; gravity,
		&lt;Real&gt; t
) {
	// declare the position function, x
	&lt;Real → Vector3&gt; x;
	
	// model x as a differential equation
	mass * Δ^2x(t)/Δt^2 = -drag * Δx(t)/Δt + mass * gravity;
	
	// with boundary conditions
	x(0) = initialPos;
	Δx(0)/Δt = initialVel;
	
	// solve, substitute, evaluate
	return x(delta_t);
};
			</pre>
		</div>

		<p>ODE solving gives a symbolic solution for x such that the following program is functionally equivalent. This constant folding is performed and cached at compile time. This result was computed manually using an existing commercial CAS, Mathematica, for demonstrative purposes. The Plange implementation exists only in concept at this time.</p>
		<div class="code2">
			<p>Example (continued)</p>
			<pre>
projectilePosition := (
		&lt;Vector3D&gt; initialPos,
		&lt;Vector3D&gt; initialVel,
		&lt;Real&gt; mass,
		&lt;Real&gt; drag,
		&lt;Vector3D&gt; gravity,
		&lt;Real&gt; t
) {
	a := 𝑒^(drag*t/mass);
	return (
			gravity * (mass-(mass*a + drag*t)) + 
			initialPos*a*drag^2 + 
			drag*mass*initialVel*(a-1)
		) / (a*drag^2);
};
			</pre>
		</div>



		<?php require('../footer.php') ?>
	</body>
</html>