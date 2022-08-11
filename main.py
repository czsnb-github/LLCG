def get_words_from_input_lines(input_lines):
    input = ''.join(line.replace('\n', ' ') for line in input_lines)
    for ch in ['(', ')', '{', '}', ',']:
        input = input.replace(ch, ' ' + ch + ' ')
    words = input.split()
    return words


def get_class_name(words):
    if 'class' not in words:
        raise RuntimeError('class is not detected in input.cpp')

    class_idx = words.index('class')
    if class_idx == len(words) - 1:
        raise RuntimeError('class name is not existed')

    class_name = words[class_idx + 1]
    return class_name


def get_func_name(words):
    dep = 0
    func_name_list = []
    for (idx, word) in enumerate(words):
        dep += {'{': 1, '}': -1}.get(word, 0)
        # print(idx, word, len(word), dep)
        if dep == 1 and word == '(':
            func_name_list.append(words[idx - 1])
    return func_name_list


def get_para_type(words, func_name):
    left_bracket = words.index(func_name) + 1
    right_bracket = words.index(')', left_bracket + 1)
    return [_.strip('&') for _ in words[left_bracket + 1: right_bracket: 3]]


def call_func(func_name, para_type, data):
    global var_id, solution_name
    code_part = ''
    for (t, v) in zip(para_type, data):
        var_id += 1
        val = v.replace('[', '{').replace(']', '}')
        if val[0] != '{':
            val = '{' + val + '}'
        code_part += '\t' + f'{t} var{var_id}{val};' + '\n'
    args = ', '.join(f'var{id}' for id in range(
        var_id - len(data) + 1, var_id + 1))
    code_part += '\t' + f'print({solution_name}->{func_name}({args}));' + '\n'
    return code_part


if __name__ == '__main__':
    input_cpp_file = open('code/input.cpp', 'r')
    solution_name = 'solution'
    var_id = 0

    input_lines = input_cpp_file.readlines()
    words = get_words_from_input_lines(input_lines)
    # print(words)

    input_data_file = open('code/input.txt', 'r')
    data = input_data_file.readlines()
    data = [_.strip('\n') for _ in data]
    print(data)

    class_name = get_class_name(words)

    func_name_list = get_func_name(words)

    code = '#include \"template/template.h\"' + '\n'
    code += ''.join(input_lines)

    if class_name == "Solution":
        code += f'Solution* {solution_name};' + '\n' + \
            "int main() {" + '\n'

        main_func_name = max(func_name_list, key=len)
        para_type_list = get_para_type(words, main_func_name)
        if len(data) % len(para_type_list) > 0:
            raise RuntimeError('mismatch between parameters and data')
        for i in range(len(data) // len(para_type_list)):
            code += '\t' + f'{solution_name} = new Solution();' + '\n'
            l_pos = i * len(para_type_list)
            r_pos = l_pos + len(para_type_list)
            code += call_func(main_func_name,
                              para_type_list, data[l_pos: r_pos])
            code += '\t' + f'delete {solution_name};' + '\n'

    code += '}'
    print(class_name)
    print(func_name_list)
    print(code)

    output_cpp_file = open('code/output.cpp', 'w')
    output_cpp_file.write(code)
    output_cpp_file.close()
