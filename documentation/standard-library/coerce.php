<meta charset='utf-8'/><html><head><title>
    rt the specified value to another type
    <div>
        <div style="font-size:13.3333330154419px;line-height:21.3333320617676px;margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
            <p style="font-size:12pt;margin:0px;padding-left:6pt;background-color:rgb(204,221,170)">
                Example
            </p>
            <pre style="margin-top:0px;margin-bottom:0px;padding:3px;font-family:Courier New;width:715px;max-height:500px;overflow:auto">
                &lt;Int&gt; x := coerce("0xff");
            </pre>
        </div>
        <div style="font-size:13.3333330154419px;line-height:21.3333320617676px">
            The target type is determined through type deduction where possible. Alternatively, the parametric form:
        </div>
    </div>
    <div>
        <div style="font-size:13.3333330154419px;line-height:21.3333320617676px;margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
            <p style="font-size:12pt;margin:0px;padding-left:6pt;background-color:rgb(204,221,170)">
                Example
            </p>
            <pre style="margin-top:0px;margin-bottom:0px;padding:3px;font-family:Courier New;width:715px;max-height:500px;overflow:auto">
                print("\nYou entered: " + coerce&lt;Number&gt;(input("Enter a number: ")));
            </pre>
        </div>
        <div style="font-size:13.3333330154419px;line-height:21.3333320617676px">
            Notably, coerce is useful for dynamic type behavior when a value respects an external interface that is did not explicitly implement.
        </div>
        <div>
            <div style="margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
                <p style="font-size:12pt;line-height:21.3333px;margin:0px;padding-left:6pt;background-color:rgb(204,221,170)">
                    Example
                </p>
                <pre style="margin-top:0px;margin-bottom:0px;padding:3px;width:715px;max-height:500px;overflow:auto">
                    <font face="Courier New">
                        <span style="font-size:13.3333px;line-height:21.3333px">
                            Human := type {
	&lt;void -&gt; void&gt; speak &lt;- () { print("Hello, world!\n"); };
};

TalkingActionFigure := type {
	&lt;void -&gt; void&gt; speak := () { print("Stay in school.\n")}
};

&lt;TalkingActionFigure&gt; amazotron;
&lt;Human&gt; canSpeak &lt;- coerce(amazotron);
canSpeak.speak();
                        </span>
                    </font>
                </pre>
            </div>
        </div>
        <div>
            <div style="margin-top:12pt;margin-bottom:12pt;border-style:solid;border-width:1px">
                <p style="font-size:12pt;line-height:21.3333320617676px;margin:0px;padding-left:6pt;background-color:rgb(204,221,170)">
                    Example
                </p>
                <pre style="margin-top:0px;margin-bottom:0px;padding:3px;width:715px;max-height:500px;overflow:auto">
                    <br>
                    </br>
                </pre>
            </div>
        </div>
        <div style="font-size:13.3333330154419px;line-height:21.3333320617676px">
            <br>
            </br>
        </div>
    </div>
../../css/general.css' type='text/css' /></head><body><?php require('../../header.php') ?>


coerce.html


<?php require('../../footer.php') ?></body></html>