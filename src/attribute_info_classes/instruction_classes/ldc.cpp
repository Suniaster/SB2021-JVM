#include "../../../include/attribute_info_classes/instruction_classes/ldc.hpp"
#include "../../../include/interpretador/reference_resolver.hpp"
using namespace Instructions;


Ldc::Ldc(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
  FileReader *f_reader = this->code_attr->class_file->file_reader;
  f_reader->readBytes(1, this->param);
}

int Ldc::execute(Frame* frame){
    CpInfo* cp_entry = this->code_attr->class_file->getConstantPoolEntry(this->param);
    switch (cp_entry->tag) {
        case 0x3:{
            CP::IntegerInfo* cp_integer = (CP::IntegerInfo *)cp_entry;
            frame->operand_stack.push(cp_integer->returnInteger(), Int);
            break;
        }
        case 0x4:{
            CP::FloatInfo* cp_float = (CP::FloatInfo *)cp_entry;
            float val = cp_float->returnFloat();
            
            frame->operand_stack.push(*(uint64_t*)&val, Float);
            break;
        }
        case 0x7:{ // Class_info
            string class_name = cp_entry->toString();
            int new_ref = ReferenceResolver::resolveClassName(class_name, frame->thread->method_area);
            frame->operand_stack.push(new_ref, Reference);
            break;
        }
        case 0x8:{ // String_info
            StringType* string_component = new StringType(cp_entry->toString());
            int heap_index = frame->thread->heap_ref->storeComponent(string_component);
            frame->operand_stack.push(heap_index, Reference);
            break;
        }
        case 0xf:{
            //CP::MethodHandleInfo* cp_class = (CP::MethodHandleInfo *)cp_entry;
            //MethodHandleType* method_handle_component = new MethodHandleType(JVMMethodHandle, cp_class);
            break;
        }
        case 0x10:{
            CP::MethodTypeInfo* cp_class = (CP::MethodTypeInfo *)cp_entry;
            StringType* string_component = new StringType(cp_class->toString());
            int heap_index = frame->thread->heap_ref->storeComponent(string_component);
            frame->operand_stack.push(heap_index, Reference);
            break;
        }
        default:{
            throw std::runtime_error("wrong LDC cpinfo tag");
        }

    }
    frame->local_pc+=2;
    return frame->local_pc+2;
}

string Ldc::toString(){
  CpInfo* cp_val = this->code_attr->class_file->getConstantPoolEntry(this->param);

  stringstream paramString;
  paramString << (int)this->param;

  return "ldc #" + paramString.str() + " <" + cp_val->toString() + ">";
}

int LdcW::execute(Frame* frame){
    CpInfo* cp_entry = this->code_attr->class_file->getConstantPoolEntry(this->param);


    switch (cp_entry->tag) {
        case 0x3:{
            CP::IntegerInfo* cp_integer = (CP::IntegerInfo *)cp_entry;
            frame->operand_stack.push(cp_integer->returnInteger(), Int);
            break;
        }
        case 0x4:{
            CP::FloatInfo* cp_float = (CP::FloatInfo *)cp_entry;
            frame->operand_stack.push(cp_float->returnFloat(), Float);
            break;
        }
        case 0x7:{
            CP::ClassInfo* cp_class = (CP::ClassInfo *)cp_entry;
            StringType* string_component = new StringType(cp_class->toString());
            int heap_index = frame->thread->heap_ref->storeComponent(string_component);
            frame->operand_stack.push(heap_index, Reference);
            break;
        }
        case 0xf:{
            //CP::MethodHandleInfo* cp_class = (CP::MethodHandleInfo *)cp_entry;
            //MethodHandleType* method_handle_component = new MethodHandleType(JVMMethodHandle, cp_class);
            break;
        }
        case 0x10:{
            CP::MethodTypeInfo* cp_class = (CP::MethodTypeInfo *)cp_entry;
            StringType* string_component = new StringType(cp_class->toString());
            int heap_index = frame->thread->heap_ref->storeComponent(string_component);
            frame->operand_stack.push(heap_index, Reference);
            break;
        }
        default:{
            throw std::runtime_error("wrong LDCW cpinfo tag");
        }

    }
    frame->local_pc+=3;
    return frame->local_pc+3;
}

LdcW::LdcW(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
  FileReader *f_reader = this->code_attr->class_file->file_reader;
  f_reader->readBytes(2, this->param);
}


int Ldc2W::execute(Frame* frame){
    CpInfo* cp_entry = this->code_attr->class_file->getConstantPoolEntry(this->param);


    switch (cp_entry->tag) {
        case 0x5:{
            CP::LongInfo* cp_long = (CP::LongInfo *)cp_entry;
            frame->operand_stack.push(cp_long->returnLong(), Long);
            break;
        }
        case 0x6:{
            CP::DoubleInfo* cp_double = (CP::DoubleInfo *)cp_entry;
            double val = cp_double->returnDouble();
            frame->operand_stack.push(*(uint64_t*)&val, Double);
            break;
        }

        default:{
            throw std::runtime_error("wrong LDC2W cpinfo tag");
        }

    }
    frame->local_pc+=3;
    return frame->local_pc+3;
}

string LdcW::toString(){
  CpInfo* cp_val = this->code_attr->class_file->getConstantPoolEntry(this->param);

  stringstream paramString;
  paramString << (int)this->param;

  return "ldc_w #" + paramString.str() + " <" + cp_val->toString() + ">";
}

Ldc2W::Ldc2W(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
  FileReader *f_reader = this->code_attr->class_file->file_reader;
  f_reader->readBytes(2, this->param);
}

string Ldc2W::toString(){
  CpInfo* cp_val = this->code_attr->class_file->getConstantPoolEntry(this->param);

  stringstream paramString;
  paramString << (int)this->param;

  return "ldc2_w #" + paramString.str() + " <" + cp_val->toString() + ">";
}

