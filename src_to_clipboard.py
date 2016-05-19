
std_files = [
  'cassert','cctype','cerrno','cfloat','ciso646','climits','clocale','cmath',
  'csetjmp','csignal','cstdarg','cstddef','cstdio','cstdlib','cstring','ctime',
  'ccomplex','cfenv','cinttypes','cstdalign','cstdbool','cstdint','ctgmath',
  'cwchar','cwctype','algorithm','bitset','complex','deque','exception',
  'fstream','functional','iomanip','ios','iosfwd','iostream','istream',
  'iterator','limits','list','locale','map','memory','new','numeric','ostream',
  'queue','set','sstream','stack','stdexcept','streambuf','string','typeinfo',
  'utility','valarray','vector','array','atomic','chrono','condition_variable',
  'forward_list','future','initializer_list','mutex','random','ratio','regex',
  'scoped_allocator','system_error','thread','tuple','typeindex','type_traits',
  'unordered_map','unordered_set', 
]

src_dir = "src/"
head_dir = "Template/"

import os
import codecs
for root, dirs, files in os.walk(src_dir):
    src_name = src_dir + files[0]
    src_file = codecs.open(src_name, 'r', 'utf-8')
    break

import re
heads = set()
output = ""
for line in src_file:
    m = re.match(r'^(#include[ ]*<)([\w.]+)(>[ ]*)$', line)
    if not m:
        output += line
        continue

    head_name = m.group(2)
    if head_name in heads:
        continue
    heads.add(head_name)

    if head_name in std_files:
        output += line
    elif head_name.find('bits/') == 0:
        output += line
    elif head_name.find('ext/') == 0:
        output += line
    else:
        head_file = codecs.open(head_dir + head_name, 'r', 'utf-8')
        output += head_file.read()

import clipboard
clipboard.copy(output)
