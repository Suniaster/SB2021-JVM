#include "../../include/constant_pool_classes/method_handle_info.hpp"



CP::MethodHandleInfo::MethodHandleInfo(ClassFile* class_file) : CpInfo(class_file){
  this->tag = 15;
}

void CP::MethodHandleInfo::setInfo(){
   // TODO checar se os valores de kind e index são válidos
  this->class_file->setAttribute<uint8_t>(1, this->reference_kind);


  this->class_file->setAttribute<uint16_t>(2, this->reference_index);
}

void CP::MethodHandleInfo::printInfo(){
  string reference_kind_text = this->getReferenceKind();

  cout << "\n\tMethodHandle: Reference Kind " << this->reference_kind;
  cout << "\t" << reference_kind_text << endl;

  cout << "\n\tMethodHandle: Reference Index cp_info#" << this->class_file->getConstantPoolEntry((int)this->reference_index)->toString() << endl;

}

string CP::MethodHandleInfo::getReferenceKind(){
    switch (this->reference_kind) {
        case 0x1:
            return "REF_getField";
            break;
        case 0x2:
            return "REF_getStatic";
            break;
        case 0x3:
            return "REF_getPutField";
            break;
        case 0x4:
            return "REF_getPutStatic";
            break;
        case 0x5:
            return "REF_invokeVirtual";
            break;
        case 0x6:
            return "REF_invokeStatic";
            break;
        case 0x7:
            return "REF_invokeSpecial";
            break;
        case 0x8:
            return "REF_newInvokeVirtual";
            break;
        case 0x9:
            return "REF_invokeInterface";
            break;
        default:
            throw std::runtime_error("wrong reference kind");
            break;
    }
}

string CP::MethodHandleInfo::getReferenceKindDescriptor(){
    switch (this->reference_kind) {
        case 0x1:
            return "(C)T";
            break;
        case 0x2:
            return "()T";
            break;
        case 0x3:
            return "(C,V)T";
            break;
        case 0x4:
            return "(T)V";
            break;
        case 0x5:
            return "(C,A*)T";
            break;
        case 0x6:
            return "(A*)T";
            break;
        case 0x7:
            return "(C,A*)T";
            break;
        case 0x8:
            return "(A*)C";
            break;
        case 0x9:
            return "(C,A*)T";
            break;
        default:
            throw std::runtime_error("wrong reference kind");
            break;
    }
}

string CP::MethodHandleInfo::getReferenceKindInterpretation(){
    switch (this->reference_kind) {
        case 0x1:
            return "getfield C.f:T";
            break;
        case 0x2:
            return "getstatic C.f:T";
            break;
        case 0x3:
            return "putfield C.f:T";
            break;
        case 0x4:
            return "putstatic C.f:T";
            break;
        case 0x5:
            return "invokevirtual C.m:(A*)T";
            break;
        case 0x6:
            return "invokestatic C.m:(A*)T";
            break;
        case 0x7:
            return "invokespecial C.m:(A*)T";
            break;
        case 0x8:
            return "new C; dup; invokespecial C.<init>:(A*)V";
            break;
        case 0x9:
            return "invokeinterface C.m:(A*)T";
            break;
        default:
            throw std::runtime_error("wrong reference kind");
            break;
    }
}
