#*-* coding: utf8 *-*
from stack import Stack


class FlexStack(Stack):
    def __getitem__(self, key):
        return self.stack[key]

    def __setitem__(self, key, val):
        self.stack[key] = val

    def __delitem__(self, key):
        del self.stack[key]

    def __contains__(self, item):
        return item in self.stack
