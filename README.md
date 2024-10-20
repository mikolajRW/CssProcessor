# CssProcessor
Task Overview
The goal of this task is to write a simple engine that processes CSS sections. 
The task requires reading CSS sections interspersed with command sections from standard input. 
The CSS sections must be parsed and stored in appropriate data structures, while the command sections need to be parsed and executed, 
with any results printed to standard output (after ==).

CSS Processing
The process begins by reading CSS declarations. The CSS is syntactically correct and consists of blocks of attributes, 
which may be preceded by selectors. Lack of selectors is valid (meaning the attributes apply to everything).

Selectors
Selectors are separated by commas. Legal CSS selectors are allowed, but it can be assumed that they do not contain commas or curly braces.

Attribute Block
The block of attributes is enclosed in curly braces. Attributes are separated by semicolons and consist of a property name and value, 
separated by a colon. After the last attribute in the block, there may or may not be a semicolon.

As attribute values, valid CSS constructs can occur, but for simplicity, it can be assumed that potential strings are safe, i.e., 
they do not contain escaped quotation marks, curly braces, or semicolons.

If a specific attribute (property) appears more than once in a block, it should be treated as one occurrence, with the last value being significant.

Simplifications:
Selectors, attribute names, and attribute values do not require semantic interpretation. For example:
margin-left: 8px and margin: 4px 7px 4px 7px should be treated as separate, unrelated attributes with the names margin-left and margin and the values 8px and 4px 7px 4px 7px, respectively.
Similarly, selectors like h1 and h1.theme should be treated as distinct, unrelated selectors.
CSS will not contain comments or @-type selectors, and blocks cannot be nested.
For testing purposes, it can be assumed that no selector or attribute is split across multiple lines (although there may be several separators or attributes in a single line).


Example::

#breadcrumb 
{
	width: 80%;
	font-size: 9pt;
}

h1, body {
	min-width: 780px;
	margin: 0;
	padding: 0;
	font-family: "Trebuchet MS", "Lucida Grande", Arial;
	font-size: 85%;
	color: #666666;
}

h1, h2, h3, h4, h5, h6 {color: #0066CB;}
????
?
1,S,?
1,S,1
1,A,?
2,A,font-family
h1,S,?
color,A,?
h1,E,color
1,A,padding
1,D,*
?
2,D,color
?

****
h1, h2, h3, h4, h5, h6 {color: #0066FF;}
????
?


Result:

? == 3
1,S,? == 1
1,S,1 == #breadcrumb
1,A,? == 2
2,A,font-family == "Trebuchet MS", "Lucida Grande", Arial
h1,S,? == 2
color,A,? == 2
h1,E,color == #0066CB
1,D,* == deleted
? == 2
2,D, color == deleted
? == 1
? == 2
