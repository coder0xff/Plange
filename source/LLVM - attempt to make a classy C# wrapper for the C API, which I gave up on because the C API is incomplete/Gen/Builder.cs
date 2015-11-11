using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using LLVMSharp;

namespace LLVM {
    partial class Builder {
        public Instruction BuildAdd(Value lhs, Value rhs, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildAdd(Underlying, lhs.Underlying, rhs.Underlying, name));
        }

        public Instruction BuildAddrSpaceCast(Value value, Type destTy, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildAddrSpaceCast(Underlying, value.Underlying, destTy.Underlying, name));
        }

        public Instruction BuildAggregateRet(Value[] retVals) {
            var retValsProxy = retVals.Select(x => x.Underlying).ToArray();
            return Instruction.FromRef(LLVMSharp.LLVM.BuildAggregateRet(Underlying, out retValsProxy[0], (uint)retValsProxy.Length));
        }

        public Instruction BuildAlloca(Type ty, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildAlloca(Underlying, ty.Underlying, name));
        }

        public Instruction BuildAnd(Value lhs, Value rhs, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildAnd(Underlying, lhs.Underlying, rhs.Underlying, name));
        }

        public Instruction BuildArrayAlloca(Type ty, Value value, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildArrayAlloca(Underlying, ty.Underlying, value.Underlying, name));
        }

        public Instruction BuildArrayMalloc(Type ty, Value value, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildArrayMalloc(Underlying, ty.Underlying, value.Underlying, name));
        }

        public Instruction BuildAShr(Value lhs, Value rhs, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildAShr(Underlying, lhs.Underlying, rhs.Underlying, name));
        }

        public Instruction BuildAtomicRMW(LLVMAtomicRMWBinOp op, Value pTR, Value value, LLVMAtomicOrdering ordering, LLVMBool singleThread) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildAtomicRMW(Underlying, op, pTR.Underlying, value.Underlying, ordering, singleThread));
        }

        public Instruction BuildBinOp(LLVMOpcode op, Value lhs, Value rhs, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildBinOp(Underlying, op, lhs.Underlying, rhs.Underlying, name));
        }

        public Instruction BuildBitCast(Value value, Type destTy, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildBitCast(Underlying, value.Underlying, destTy.Underlying, name));
        }

        public Instruction BuildBr(BasicBlock dest) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildBr(Underlying, dest.Underlying));
        }

        public Instruction BuildCall(Value fn, Value[] args, String name) {
            var argsProxy = args.Select(x => x.Underlying).ToArray();
            return Instruction.FromRef(LLVMSharp.LLVM.BuildCall(Underlying, fn.Underlying, out argsProxy[0], (uint)argsProxy.Length, name));
        }

        public Instruction BuildCast(LLVMOpcode op, Value value, Type destTy, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildCast(Underlying, op, value.Underlying, destTy.Underlying, name));
        }

        public Instruction BuildCondBr(Value _if, BasicBlock then, BasicBlock _else) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildCondBr(Underlying, _if.Underlying, then.Underlying, _else.Underlying));
        }

        public Instruction BuildExactSDiv(Value lhs, Value rhs, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildExactSDiv(Underlying, lhs.Underlying, rhs.Underlying, name));
        }

        public Instruction BuildExtractElement(Value vecVal, Value index, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildExtractElement(Underlying, vecVal.Underlying, index.Underlying, name));
        }

        public Instruction BuildExtractValue(Value aggVal, UInt32 index, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildExtractValue(Underlying, aggVal.Underlying, index, name));
        }

        public Instruction BuildFAdd(Value lhs, Value rhs, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildFAdd(Underlying, lhs.Underlying, rhs.Underlying, name));
        }

        public Instruction BuildFCmp(LLVMRealPredicate op, Value lhs, Value rhs, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildFCmp(Underlying, op, lhs.Underlying, rhs.Underlying, name));
        }

        public Instruction BuildFDiv(Value lhs, Value rhs, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildFDiv(Underlying, lhs.Underlying, rhs.Underlying, name));
        }

        public Instruction BuildFence(LLVMAtomicOrdering ordering, LLVMBool singleThread, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildFence(Underlying, ordering, singleThread, name));
        }

        public Instruction BuildFMul(Value lhs, Value rhs, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildFMul(Underlying, lhs.Underlying, rhs.Underlying, name));
        }

        public Instruction BuildFNeg(Value v, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildFNeg(Underlying, v.Underlying, name));
        }

        public Instruction BuildFPCast(Value value, Type destTy, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildFPCast(Underlying, value.Underlying, destTy.Underlying, name));
        }

        public Instruction BuildFPExt(Value value, Type destTy, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildFPExt(Underlying, value.Underlying, destTy.Underlying, name));
        }

        public Instruction BuildFPToSI(Value value, Type destTy, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildFPToSI(Underlying, value.Underlying, destTy.Underlying, name));
        }

        public Instruction BuildFPToUI(Value value, Type destTy, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildFPToUI(Underlying, value.Underlying, destTy.Underlying, name));
        }

        public Instruction BuildFPTrunc(Value value, Type destTy, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildFPTrunc(Underlying, value.Underlying, destTy.Underlying, name));
        }

        public Instruction BuildFree(Value pointerVal) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildFree(Underlying, pointerVal.Underlying));
        }

        public Instruction BuildFRem(Value lhs, Value rhs, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildFRem(Underlying, lhs.Underlying, rhs.Underlying, name));
        }

        public Instruction BuildFSub(Value lhs, Value rhs, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildFSub(Underlying, lhs.Underlying, rhs.Underlying, name));
        }

        public Instruction BuildGEP(Value pointer, Value[] indices, String name) {
            var indicesProxy = indices.Select(x => x.Underlying).ToArray();
            return Instruction.FromRef(LLVMSharp.LLVM.BuildGEP(Underlying, pointer.Underlying, out indicesProxy[0], (uint)indicesProxy.Length, name));
        }

        public Instruction BuildGlobalString(String str, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildGlobalString(Underlying, str, name));
        }

        public Instruction BuildGlobalStringPtr(String str, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildGlobalStringPtr(Underlying, str, name));
        }

        public Instruction BuildICmp(LLVMIntPredicate op, Value lhs, Value rhs, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildICmp(Underlying, op, lhs.Underlying, rhs.Underlying, name));
        }

        public Instruction BuildInBoundsGEP(Value pointer, Value[] indices, String name) {
            var indicesProxy = indices.Select(x => x.Underlying).ToArray();
            return Instruction.FromRef(LLVMSharp.LLVM.BuildInBoundsGEP(Underlying, pointer.Underlying, out indicesProxy[0], (uint)indicesProxy.Length, name));
        }

        public Instruction BuildIndirectBr(Value addr, UInt32 numDests) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildIndirectBr(Underlying, addr.Underlying, numDests));
        }

        public Instruction BuildInsertElement(Value vecVal, Value eltVal, Value index, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildInsertElement(Underlying, vecVal.Underlying, eltVal.Underlying, index.Underlying, name));
        }

        public Instruction BuildInsertValue(Value aggVal, Value eltVal, UInt32 index, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildInsertValue(Underlying, aggVal.Underlying, eltVal.Underlying, index, name));
        }

        public Instruction BuildIntCast(Value value, Type destTy, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildIntCast(Underlying, value.Underlying, destTy.Underlying, name));
        }

        public Instruction BuildIntToPtr(Value value, Type destTy, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildIntToPtr(Underlying, value.Underlying, destTy.Underlying, name));
        }

        public Instruction BuildInvoke(Value fn, Value[] args, BasicBlock then, BasicBlock _catch, String name) {
            var argsProxy = args.Select(x => x.Underlying).ToArray();
            return Instruction.FromRef(LLVMSharp.LLVM.BuildInvoke(Underlying, fn.Underlying, out argsProxy[0], (uint)argsProxy.Length, then.Underlying, _catch.Underlying, name));
        }

        public Instruction BuildIsNotNull(Value value, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildIsNotNull(Underlying, value.Underlying, name));
        }

        public Instruction BuildIsNull(Value value, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildIsNull(Underlying, value.Underlying, name));
        }

        public Instruction BuildLandingPad(Type ty, Value persFn, UInt32 numClauses, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildLandingPad(Underlying, ty.Underlying, persFn.Underlying, numClauses, name));
        }

        public Instruction BuildLoad(Value pointerVal, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildLoad(Underlying, pointerVal.Underlying, name));
        }

        public Instruction BuildLShr(Value lhs, Value rhs, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildLShr(Underlying, lhs.Underlying, rhs.Underlying, name));
        }

        public Instruction BuildMalloc(Type ty, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildMalloc(Underlying, ty.Underlying, name));
        }

        public Instruction BuildMul(Value lhs, Value rhs, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildMul(Underlying, lhs.Underlying, rhs.Underlying, name));
        }

        public Instruction BuildNeg(Value v, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildNeg(Underlying, v.Underlying, name));
        }

        public Instruction BuildNot(Value v, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildNot(Underlying, v.Underlying, name));
        }

        public Instruction BuildNSWAdd(Value lhs, Value rhs, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildNSWAdd(Underlying, lhs.Underlying, rhs.Underlying, name));
        }

        public Instruction BuildNSWMul(Value lhs, Value rhs, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildNSWMul(Underlying, lhs.Underlying, rhs.Underlying, name));
        }

        public Instruction BuildNSWNeg(Value v, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildNSWNeg(Underlying, v.Underlying, name));
        }

        public Instruction BuildNSWSub(Value lhs, Value rhs, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildNSWSub(Underlying, lhs.Underlying, rhs.Underlying, name));
        }

        public Instruction BuildNUWAdd(Value lhs, Value rhs, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildNUWAdd(Underlying, lhs.Underlying, rhs.Underlying, name));
        }

        public Instruction BuildNUWMul(Value lhs, Value rhs, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildNUWMul(Underlying, lhs.Underlying, rhs.Underlying, name));
        }

        public Instruction BuildNUWNeg(Value v, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildNUWNeg(Underlying, v.Underlying, name));
        }

        public Instruction BuildNUWSub(Value lhs, Value rhs, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildNUWSub(Underlying, lhs.Underlying, rhs.Underlying, name));
        }

        public Instruction BuildOr(Value lhs, Value rhs, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildOr(Underlying, lhs.Underlying, rhs.Underlying, name));
        }

        public Instruction BuildPhi(Type ty, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildPhi(Underlying, ty.Underlying, name));
        }

        public Instruction BuildPointerCast(Value value, Type destTy, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildPointerCast(Underlying, value.Underlying, destTy.Underlying, name));
        }

        public Instruction BuildPtrDiff(Value lhs, Value rhs, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildPtrDiff(Underlying, lhs.Underlying, rhs.Underlying, name));
        }

        public Instruction BuildPtrToInt(Value value, Type destTy, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildPtrToInt(Underlying, value.Underlying, destTy.Underlying, name));
        }

        public Instruction BuildResume(Value exn) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildResume(Underlying, exn.Underlying));
        }

        public Instruction BuildRet(Value v) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildRet(Underlying, v.Underlying));
        }

        public Instruction BuildRetVoid() {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildRetVoid(Underlying));
        }

        public Instruction BuildSDiv(Value lhs, Value rhs, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildSDiv(Underlying, lhs.Underlying, rhs.Underlying, name));
        }

        public Instruction BuildSelect(Value _if, Value then, Value _else, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildSelect(Underlying, _if.Underlying, then.Underlying, _else.Underlying, name));
        }

        public Instruction BuildSExt(Value value, Type destTy, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildSExt(Underlying, value.Underlying, destTy.Underlying, name));
        }

        public Instruction BuildSExtOrBitCast(Value value, Type destTy, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildSExtOrBitCast(Underlying, value.Underlying, destTy.Underlying, name));
        }

        public Instruction BuildShl(Value lhs, Value rhs, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildShl(Underlying, lhs.Underlying, rhs.Underlying, name));
        }

        public Instruction BuildShuffleVector(Value v1, Value v2, Value mask, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildShuffleVector(Underlying, v1.Underlying, v2.Underlying, mask.Underlying, name));
        }

        public Instruction BuildSIToFP(Value value, Type destTy, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildSIToFP(Underlying, value.Underlying, destTy.Underlying, name));
        }

        public Instruction BuildSRem(Value lhs, Value rhs, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildSRem(Underlying, lhs.Underlying, rhs.Underlying, name));
        }

        public Instruction BuildStore(Value value, Value ptr) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildStore(Underlying, value.Underlying, ptr.Underlying));
        }

        public Instruction BuildStructGEP(Value pointer, UInt32 idx, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildStructGEP(Underlying, pointer.Underlying, idx, name));
        }

        public Instruction BuildSub(Value lhs, Value rhs, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildSub(Underlying, lhs.Underlying, rhs.Underlying, name));
        }

        public Instruction BuildSwitch(Value v, BasicBlock _else, UInt32 numCases) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildSwitch(Underlying, v.Underlying, _else.Underlying, numCases));
        }

        public Instruction BuildTrunc(Value value, Type destTy, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildTrunc(Underlying, value.Underlying, destTy.Underlying, name));
        }

        public Instruction BuildTruncOrBitCast(Value value, Type destTy, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildTruncOrBitCast(Underlying, value.Underlying, destTy.Underlying, name));
        }

        public Instruction BuildUDiv(Value lhs, Value rhs, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildUDiv(Underlying, lhs.Underlying, rhs.Underlying, name));
        }

        public Instruction BuildUIToFP(Value value, Type destTy, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildUIToFP(Underlying, value.Underlying, destTy.Underlying, name));
        }

        public Instruction BuildUnreachable() {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildUnreachable(Underlying));
        }

        public Instruction BuildURem(Value lhs, Value rhs, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildURem(Underlying, lhs.Underlying, rhs.Underlying, name));
        }

        public Instruction BuildVAArg(Value list, Type ty, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildVAArg(Underlying, list.Underlying, ty.Underlying, name));
        }

        public Instruction BuildXor(Value lhs, Value rhs, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildXor(Underlying, lhs.Underlying, rhs.Underlying, name));
        }

        public Instruction BuildZExt(Value value, Type destTy, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildZExt(Underlying, value.Underlying, destTy.Underlying, name));
        }

        public Instruction BuildZExtOrBitCast(Value value, Type destTy, String name) {
            return Instruction.FromRef(LLVMSharp.LLVM.BuildZExtOrBitCast(Underlying, value.Underlying, destTy.Underlying, name));
        }

    }
}
