/**
 * @author Nicholas Kidd
 * @version $Revision$
 */

#include <functional>
#include "wali/Common.hpp"
#include "wali/LLVMValueSource.hpp"
#include "wali/hm_hash.hpp"
#include <llvm/Support/raw_ostream.h>

namespace wali
{
  LLVMValueSource::LLVMValueSource( const llvm::Value *v ) : value(v) {}

  LLVMValueSource::~LLVMValueSource() {}

  bool LLVMValueSource::equal( KeySource* rhs )
  {
    LLVMValueSource *vsrc = dynamic_cast< LLVMValueSource* >(rhs);
    if( vsrc != 0 )
      return value == vsrc->value;
    else
      return false;
  }

  size_t LLVMValueSource::hash() const
  {
    return std::hash<size_t>()(reinterpret_cast<size_t>(value));
  }

  std::ostream& LLVMValueSource::print( std::ostream& o ) const
  {
    std::string irbuffer;
    llvm::raw_string_ostream rso(irbuffer);
    value->print(rso);
    rso.flush();
    irbuffer = irbuffer.substr(0,
      (irbuffer.find(", align") != std::string::npos) ?
         irbuffer.find(", align") :
         irbuffer.size());
    irbuffer = irbuffer.substr(0,
      (irbuffer.find("!phasar.") != std::string::npos) ?
         irbuffer.find("!phasar.") :
         irbuffer.size());
    return o << irbuffer;
  }

  const llvm::Value *LLVMValueSource::getLLVMValue() const
  {
    return value;
  }

} // namespace wali

