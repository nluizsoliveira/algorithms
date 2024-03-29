
from project.modules.binary_handlers.file import File

# IMPROVE: Create Index class. Inherit SeconderyIndex and PrimaryIndex from Index
class SecondaryIndex():
    SEP_1 = '|'
    SEP_2 = ','
    SEP_3 = '\n'

    def __init__(self, path):  
        self.path = path
        self.file = File(self.path)
        self.RAM_index = self.get_RAM_index()

    def append(self, key, value):
        current_values = self.RAM_index.get(key)
        if current_values:
            current_values.append(value)
        else:
            self.RAM_index.update({key: [value]})

    def search(self, key):
        return self.RAM_index.get(key)
    
    def get_RAM_index(self):
        if self.file.size: 
            return self.read_RAM_index_from_file()
        else:
            return {}

    def read_RAM_index_from_file(self):
        buffer = self.file.read_entire_file()
        str_buffer = str(buffer, encoding='utf-8')
        index_lines = str_buffer.split()
        RAM_index = {}
        for line in index_line:
            key, values = line.split(self.SEP_1)
            ids = values.split(self.SEP_2)
            RAM_index.update({key: ids})
        return RAM_index
    
    def remove_key(self, key):
        return self.RAM_index.pop(key, None)
    
    def remove_value(self, key, value):
        values = self.RAM_index.get(key)
        values.remove(value)
        return value
    
    def update_file(self):
        buffer = ""
        active_records =  len(self.RAM_index)
        file = open(self.path, 'w')
        for key, values in self.RAM_index.items():
            line = self.get_index_line(key, values)
            buffer += line
        file.write(buffer)
        file.close()

        self.file.size = active_records

    def get_index_line(self, key, values):
        values_str = ""
        for value in values:
            values_str+=f'{value}{self.SEP_2}'
        return f'{key}{self.SEP_1}{values_str}{self.SEP_3}'
