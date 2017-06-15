class Option:
    def __init__(self, child):
        self.child = child

class Repetition:
    def __init__(self, child):
        self.child = child

class Sequence:
    def __init__(self, children):
        self.children = children

class Variant:
    def __init__(self, children):
        self.children = children

class Identifier:
    def __init__(self, name):
        self.name = name

class Literal:
    def __init__(self, text):
        self.text = text

class Production:
    def __init__(self, name, text):
        self.name = name
        (i, self.tree) = self.parse_expression(text, 0)

    def skip_whitespace(self, text, i):
        while i < len(text) and text[i].isspace():
            i += 1
        return i

    def parse_expression(self, text, i):
        old_i = i
        children = list()
        i = self.skip_whitespace(text, i)
        while True:
            (i, term) = self.parse_term(text, i)
            i = self.skip_whitespace(text, i)
            if term:
                children.append(term)
            if not term or i >= len(text) or not text[i] == "|":
                break
            i += 1
        if len(children) == 0:
            return (old_i, None)
        elif len(children) == 1:
            return (i, children[0])
        else:
            return (i, Variant(children))

    def parse_term(self, text, i):
        old_i = i
        children = list()
        i = self.skip_whitespace(text, i)
        while True:
            (i, factor) = self.parse_factor(text, i)
            i = self.skip_whitespace(text, i)
            if factor:
                children.append(factor)
            if not factor or i >= len(text):
                break
        if len(children) == 0:
            return (old_i, None)
        elif len(children) == 1:
            return (i, children[0])
        else:
            return (i, Sequence(children))

    def parse_factor(self, text, i):
        (i, identifier) = self.parse_identifier(text, i)
        if identifier:
            return (i, identifier)
        (i, literal) = self.parse_literal(text, i)
        if literal:
            return (i, literal)

        old_i = i
        i = self.skip_whitespace(text, i)
        if i < len(text):
            if text[i] == "[":
                i += 1
                (i, expression) = self.parse_expression(text, i)
                if expression:
                    i = self.skip_whitespace(text, i)
                    if not i < len(text) or not text[i] == "]":
                        raise Exception("expected ] at " + str(i))
                    i += 1
                    return (i, Option(expression))

            if text[i] == "(":
                i += 1
                (i, expression) = self.parse_expression(text, i)
                if expression:
                    i = self.skip_whitespace(text, i)
                    if not i < len(text) or not text[i] == ")":
                        raise Exception("expected ) at " + str(i))
                    i += 1
                    return (i, expression)

            if text[i] == "{":
                i += 1
                (i, expression) = self.parse_expression(text, i)
                if expression:
                    i = self.skip_whitespace(text, i)
                    if not i < len(text) or not text[i] == "}":
                        raise Exception("expected } at " + str(i))
                    i += 1
                    return (i, Repetition(expression))

        return (old_i, None)

    def parse_identifier(self, text, i):
        old_i = i
        i = self.skip_whitespace(text, i)
        result = ""
        if i < len(text):
            if text[i].isalpha():
                result += text[i]
                i += 1
                while i < len(text) and (text[i].isalpha() or text[i] == "_"):
                    result += text[i]
                    i += 1
        if not result == "":
            return (i, Identifier(result))
        else:
            return (old_i, None)


    def parse_literal(self, text, i):
        escapes = {
            "n": "\n",
            "r": "\r",
            "t": "\t",
            "b": "\b",
            "f": "\f",
            "v": "\v",
            "0": "\0"
        }

        old_i = i
        i = self.skip_whitespace(text, i)
        if i >= len(text) or text[i] != "\"":
            return (old_i, None)
        i += 1
        result = ""
        while i < len(text) and not text[i] == "\"":
            if text[i] == "\\":
                i += 1
                if i < len(text):
                    c = text[i]
                    i += 1
                    if c in escapes:
                        result += escapes[c]
                    else:
                        result += c
            else:
                result += text[i]
                i += 1
        if not text[i] == "\"":
            raise Exception("expected \" at " + str(i))
        i += 1
        return (i, Literal(result))