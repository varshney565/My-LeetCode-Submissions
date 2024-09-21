<h2><a href="https://leetcode.com/problems/count-and-say/">38. Count and Say</a></h2><h3>Medium</h3><hr><div><p>The <strong>count-and-say</strong> sequence is a sequence of digit strings defined by the recursive formula:</p>

<ul>
	<li><code style="">countAndSay(1) = "1"</code></li>
	<li><code style="">countAndSay(n)</code> is the run-length encoding of <code style="">countAndSay(n - 1)</code>.</li>
</ul>

<p><a href="http://en.wikipedia.org/wiki/Run-length_encoding" target="_blank">Run-length encoding</a> (RLE) is a string compression method that works by replacing consecutive identical characters (repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters (length of the run). For example, to compress the string <code style="">"3322251"</code> we replace <code style="">"33"</code> with <code style="">"23"</code>, replace <code style="">"222"</code> with <code style="">"32"</code>, replace <code style="">"5"</code> with <code style="">"15"</code> and replace <code style="">"1"</code> with <code style="">"11"</code>. Thus the compressed string becomes <code style="">"23321511"</code>.</p>

<p>Given a positive integer <code style="">n</code>, return <em>the </em><code style="">n<sup>th</sup></code><em> element of the <strong>count-and-say</strong> sequence</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 4</span></p>

<p><strong>Output:</strong> <span class="example-io">"1211"</span></p>

<p><strong>Explanation:</strong></p>

<pre style="">countAndSay(1) = "1"
countAndSay(2) = RLE of "1" = "11"
countAndSay(3) = RLE of "11" = "21"
countAndSay(4) = RLE of "21" = "1211"
</pre>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 1</span></p>

<p><strong>Output:</strong> <span class="example-io">"1"</span></p>

<p><strong>Explanation:</strong></p>

<p>This is the base case.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code style="">1 &lt;= n &lt;= 30</code></li>
</ul>

<p>&nbsp;</p>
<strong>Follow up:</strong> Could you solve it iteratively?</div>