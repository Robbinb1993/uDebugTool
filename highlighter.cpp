/*
This is a C++ port of the following PyQt example
http://diotavelli.net/PyQtWiki/Python%20syntax%20highlighting
C++ port by Frankie Simon (www.kickdrive.de, www.fuh-edv.de)
The following free software license applies for this file ("X11 license"):
Permission is hereby granted, free of charge, to any person obtaining a copy of this software
and associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:
The above copyright notice and this permission notice shall be included in all copies or substantial
portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT
LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE X CONSORTIUM BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE
USE OR OTHER DEALINGS IN THE SOFTWARE.
SyntaxHighlighter.cpp

   Created on: 21.10.2016
   Author: klemens.morgenstern
 */

#include <highlighter.h>
#include <QDebug>

SyntaxHighlighter::SyntaxHighlighter(QTextDocument *parent)
 : QSyntaxHighlighter(parent)
{
    keywords = QStringList() << "auto" << "break" << "class" << "else" << "int16_t" << "int32_t" <<
            "int64_t" << "for" << "fun" << "if" << "try" << "catch" << "while" << "var" << "int" << "true" <<
            "false" << "auto" << "bool" << "break" << "case" << "char" << "char16_t" << "char32_t" <<
            "class" << "const" << "constexpr" << "const_cast" << "continue" << "decltype" << "default" <<
            "delete" << "do" << "double" << "dynamic_cast" << "enum" << "explicit" << "float" <<
            "friend" << "goto" << "inline" << "long" << "namespace" << "mutable" << "new" << "noexcept" <<
            "not" << "and" << "and_eq" << "not_eq" << "nullptr" << "operator" << "or" << "or_eq" << "private" <<
            "protected" << "public" << "register" << "reinterpret_cast" << "return" << "short" << "signed" <<
            "sizeof" << "static" << "static_assert" << "struct" << "switch" << "template" << "this" << "throw" <<
            "typedef" << "typename" << "union" << "unsigned" << "using" << "virtual" << "void" << "volatile" <<
            "wchar_t" << "while" << "xor" << "xor_eq";

    std = QStringList() << "array" << "vector" << "deque" << "forward_list" << "list" << "stack" <<
            "queue" << "priority_queue" << "set" << "multiset" << "map" << "multimap" << "unordered_set" <<
            "unordered_multiset" << "unordered_map" << "unordered_multimap" << "bitset" << "pair" << "tuple" <<
            "cin" << "cout" << "std" << "endl" << "iostream" << "clear" << "push_back" << "empty" << "sort" <<
            "next_permutation" << "prv_permutation" << "size" << "min" << "max" << "begin" << "end" << "iterator" <<
            "lower_bound" << "upper_bound" << "find" << "string" << "rank" << "front" << "back" << "lesser" << "greater" <<
            "swap" << "erase" << "rbegin" << "rend";

    operators = QStringList() << "=" <<
           // Comparison
           "==" << "!=" << "<" << "<=" << ">" << ">=" << "!" << "\\?" <<
           // Arithmetic
           "\\+" << "-" << "\\*" << "/" << "//" << "%" << "\\*\\*" <<
           // In-place
           "\\+=" << "-=" << "\\*=" << "/=" << "%=" <<
           // Bitwise
           "\\^" << "\\|" << "&" << "~" << ">>" << "<<" <<
           // Separators
           "\\," << "\\." << "\\:" << "\\;";

    braces = QStringList() << "\\{" << "\\}" << "\\(" << "\\)" << "\\[" << "\\]";

    basicStyles.insert("keyword", getTextCharFormat("MediumBlue", "bold"));
    basicStyles.insert("std", getTextCharFormat("ForestGreen", "bold"));
    basicStyles.insert("operator", getTextCharFormat("red"));
    basicStyles.insert("brace", getTextCharFormat("red"));
    basicStyles.insert("braces", getTextCharFormat("darkGray"));
    basicStyles.insert("string", getTextCharFormat("blue"));
    basicStyles.insert("comment", getTextCharFormat("ForestGreen", "italic"));
    basicStyles.insert("include", getTextCharFormat("ForestGreen", "italic"));
    basicStyles.insert("define", getTextCharFormat("ForestGreen", "italic"));
    basicStyles.insert("numbers", getTextCharFormat("magenta"));
    basicStyles.insert("characters", getTextCharFormat("DarkOrange"));

    multiLineCommentFormat = getTextCharFormat("ForestGreen ", "italic");
    commentStartExpression = QRegularExpression("/\\*");
    commentEndExpression = QRegularExpression("\\*/");

    initializeRules();
}

void SyntaxHighlighter::initializeRules()
{
    for (auto & currKeyword : keywords)
    {
        rules.append(HighlightRule(QString("\\b%1\\b").arg(currKeyword), 0, basicStyles.value("keyword")));
    }
    for (auto & currStdElement : std) {
        rules.append(HighlightRule(QString("\\b%1\\b").arg(currStdElement), 0, basicStyles.value("std")));
    }
    for (auto & currOperator : operators)
    {
        rules.append(HighlightRule(QString("%1").arg(currOperator), 0, basicStyles.value("operator")));
    }
    for (auto & currBrace : braces)
    {
        rules.append(HighlightRule(QString("%1").arg(currBrace), 0, basicStyles.value("brace")));
    }    

    // Numeric literals
    rules.append(HighlightRule("\\b[+-]?[0-9]+[lL]?\\b", 0, basicStyles.value("numbers"))); // r'\b[+-]?[0-9]+[lL]?\b'
    rules.append(HighlightRule("\\b[+-]?0[xX][0-9A-Fa-f]+[lL]?\\b", 0, basicStyles.value("numbers"))); // r'\b[+-]?0[xX][0-9A-Fa-f]+[lL]?\b'
    rules.append(HighlightRule("\\b[+-]?[0-9]+(?:\\.[0-9]+)?(?:[eE][+-]?[0-9]+)?\\b", 0, basicStyles.value("numbers"))); // r'\b[+-]?[0-9]+(?:\.[0-9]+)?(?:[eE][+-]?[0-9]+)?\b'

    //Characters
    rules.append(HighlightRule("'[^'\\\\]*(\\\\.[^'\\\\]*)*'", 0, basicStyles.value("characters")));

    //Strings
    rules.append(HighlightRule("\"[^\"\\\\]*(\\\\.[^\"\\\\]*)*\"", 0, basicStyles.value("string")));

    //Comments
    rules.append(HighlightRule("//[^\\n]*", 0, basicStyles.value("comment")));

    // Includes
    rules.append(HighlightRule("#include[^\\n]*", 0, basicStyles.value("include")));

    // Defines
    rules.append(HighlightRule("#define[^\\n]*", 0, basicStyles.value("define")));
}

void SyntaxHighlighter::highlightBlock(const QString &text)
{
    for (HighlightRule & currRule : rules)
    {
        int idx = currRule.pattern.indexIn(text, 0);
        while (idx >= 0)
        {
            // Get index of Nth match
            idx = currRule.pattern.pos(currRule.nth);
            int length = currRule.pattern.cap(currRule.nth).length();
            setFormat(idx, length, currRule.format);
            idx = currRule.pattern.indexIn(text, idx + length);
        }
    }

    setCurrentBlockState(0);

    int startIndex = 0;
    if (previousBlockState() != 1)
        startIndex = text.indexOf(commentStartExpression);
    while (startIndex >= 0) {
    //! [10] //! [11]
        QRegularExpressionMatch match = commentEndExpression.match(text, startIndex);
        int endIndex = match.capturedStart();
        int commentLength = 0;
        if (endIndex == -1) {
            setCurrentBlockState(1);
            commentLength = text.length() - startIndex;
        } else {
            commentLength = endIndex - startIndex
                            + match.capturedLength();
        }
        setFormat(startIndex, commentLength, multiLineCommentFormat);
        startIndex = text.indexOf(commentStartExpression, startIndex + commentLength);
    }
}

bool SyntaxHighlighter::matchMultiline(const QString &text, const QRegExp &delimiter, const int inState, const QTextCharFormat &style)
{
    int start = -1;
    int add = -1;
    int end = -1;
    int length = 0;

    // If inside triple-single quotes, start at 0
    if (previousBlockState() == inState)
    {
        start = 0;
        add = 0;
    }
    // Otherwise, look for the delimiter on this line
    else {
        start = delimiter.indexIn(text);
        // Move past this match
        add = delimiter.matchedLength();
    }

    // As long as there's a delimiter match on this line...
    while (start >= 0)
    {
        // Look for the ending delimiter
        end = delimiter.indexIn(text, start + add);
        // Ending delimiter on this line?
        if (end >= add) {
            length = end - start + add + delimiter.matchedLength();
            setCurrentBlockState(0);
    }
        // No; multi-line string
        else {
            setCurrentBlockState(inState);
            length = text.length() - start + add;
    }
        // Apply formatting and look for next
        setFormat(start, length, style);
        start = delimiter.indexIn(text, start + length);
    }
    // Return True if still inside a multi-line string, False otherwise
    if (currentBlockState() == inState)
        return true;
    else
        return false;
}

const QTextCharFormat SyntaxHighlighter::getTextCharFormat(const QString &colorName, const QString &style)
{
    QTextCharFormat charFormat;
    QColor color(colorName);
    charFormat.setForeground(color);
    if (style.contains("bold", Qt::CaseInsensitive))
        charFormat.setFontWeight(QFont::Bold);
    if (style.contains("italic", Qt::CaseInsensitive))
        charFormat.setFontItalic(true);
    return charFormat;
}

