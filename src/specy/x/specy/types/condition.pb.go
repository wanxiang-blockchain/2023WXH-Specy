// Code generated by protoc-gen-gogo. DO NOT EDIT.
// source: specy/specy/condition.proto

package types

import (
	fmt "fmt"
	proto "github.com/gogo/protobuf/proto"
	io "io"
	math "math"
	math_bits "math/bits"
)

// Reference imports to suppress errors if they are not otherwise used.
var _ = proto.Marshal
var _ = fmt.Errorf
var _ = math.Inf

// This is a compile-time assertion to ensure that this generated file
// is compatible with the proto package it is being compiled against.
// A compilation error at this line likely means your copy of the
// proto package needs to be updated.
const _ = proto.GoGoProtoPackageIsVersion3 // please upgrade the proto package

type Condition struct {
	IntervalType uint64 `protobuf:"varint,1,opt,name=intervalType,proto3" json:"intervalType,omitempty"`
	Number       uint64 `protobuf:"varint,2,opt,name=number,proto3" json:"number,omitempty"`
}

func (m *Condition) Reset()         { *m = Condition{} }
func (m *Condition) String() string { return proto.CompactTextString(m) }
func (*Condition) ProtoMessage()    {}
func (*Condition) Descriptor() ([]byte, []int) {
	return fileDescriptor_d42679efa6520302, []int{0}
}
func (m *Condition) XXX_Unmarshal(b []byte) error {
	return m.Unmarshal(b)
}
func (m *Condition) XXX_Marshal(b []byte, deterministic bool) ([]byte, error) {
	if deterministic {
		return xxx_messageInfo_Condition.Marshal(b, m, deterministic)
	} else {
		b = b[:cap(b)]
		n, err := m.MarshalToSizedBuffer(b)
		if err != nil {
			return nil, err
		}
		return b[:n], nil
	}
}
func (m *Condition) XXX_Merge(src proto.Message) {
	xxx_messageInfo_Condition.Merge(m, src)
}
func (m *Condition) XXX_Size() int {
	return m.Size()
}
func (m *Condition) XXX_DiscardUnknown() {
	xxx_messageInfo_Condition.DiscardUnknown(m)
}

var xxx_messageInfo_Condition proto.InternalMessageInfo

func (m *Condition) GetIntervalType() uint64 {
	if m != nil {
		return m.IntervalType
	}
	return 0
}

func (m *Condition) GetNumber() uint64 {
	if m != nil {
		return m.Number
	}
	return 0
}

func init() {
	proto.RegisterType((*Condition)(nil), "specynetwork.specy.specy.Condition")
}

func init() { proto.RegisterFile("specy/specy/condition.proto", fileDescriptor_d42679efa6520302) }

var fileDescriptor_d42679efa6520302 = []byte{
	// 172 bytes of a gzipped FileDescriptorProto
	0x1f, 0x8b, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xff, 0xe2, 0x92, 0x2e, 0x2e, 0x48, 0x4d,
	0xae, 0xd4, 0x87, 0x90, 0xc9, 0xf9, 0x79, 0x29, 0x99, 0x25, 0x99, 0xf9, 0x79, 0x7a, 0x05, 0x45,
	0xf9, 0x25, 0xf9, 0x42, 0x12, 0x60, 0xe1, 0xbc, 0xd4, 0x92, 0xf2, 0xfc, 0xa2, 0x6c, 0x3d, 0x30,
	0x07, 0x42, 0x2a, 0xb9, 0x73, 0x71, 0x3a, 0xc3, 0x14, 0x0b, 0x29, 0x71, 0xf1, 0x64, 0xe6, 0x95,
	0xa4, 0x16, 0x95, 0x25, 0xe6, 0x84, 0x54, 0x16, 0xa4, 0x4a, 0x30, 0x2a, 0x30, 0x6a, 0xb0, 0x04,
	0xa1, 0x88, 0x09, 0x89, 0x71, 0xb1, 0xe5, 0x95, 0xe6, 0x26, 0xa5, 0x16, 0x49, 0x30, 0x81, 0x65,
	0xa1, 0x3c, 0x27, 0xb7, 0x13, 0x8f, 0xe4, 0x18, 0x2f, 0x3c, 0x92, 0x63, 0x7c, 0xf0, 0x48, 0x8e,
	0x71, 0xc2, 0x63, 0x39, 0x86, 0x0b, 0x8f, 0xe5, 0x18, 0x6e, 0x3c, 0x96, 0x63, 0x88, 0xd2, 0x49,
	0xcf, 0x2c, 0xc9, 0x28, 0x4d, 0xd2, 0x4b, 0xce, 0xcf, 0x85, 0x38, 0x4f, 0x17, 0xea, 0x10, 0xa8,
	0x63, 0x2b, 0xa0, 0x74, 0x49, 0x65, 0x41, 0x6a, 0x71, 0x12, 0x1b, 0xd8, 0xc5, 0xc6, 0x80, 0x00,
	0x00, 0x00, 0xff, 0xff, 0x43, 0xd4, 0xf1, 0x79, 0xd0, 0x00, 0x00, 0x00,
}

func (m *Condition) Marshal() (dAtA []byte, err error) {
	size := m.Size()
	dAtA = make([]byte, size)
	n, err := m.MarshalToSizedBuffer(dAtA[:size])
	if err != nil {
		return nil, err
	}
	return dAtA[:n], nil
}

func (m *Condition) MarshalTo(dAtA []byte) (int, error) {
	size := m.Size()
	return m.MarshalToSizedBuffer(dAtA[:size])
}

func (m *Condition) MarshalToSizedBuffer(dAtA []byte) (int, error) {
	i := len(dAtA)
	_ = i
	var l int
	_ = l
	if m.Number != 0 {
		i = encodeVarintCondition(dAtA, i, uint64(m.Number))
		i--
		dAtA[i] = 0x10
	}
	if m.IntervalType != 0 {
		i = encodeVarintCondition(dAtA, i, uint64(m.IntervalType))
		i--
		dAtA[i] = 0x8
	}
	return len(dAtA) - i, nil
}

func encodeVarintCondition(dAtA []byte, offset int, v uint64) int {
	offset -= sovCondition(v)
	base := offset
	for v >= 1<<7 {
		dAtA[offset] = uint8(v&0x7f | 0x80)
		v >>= 7
		offset++
	}
	dAtA[offset] = uint8(v)
	return base
}
func (m *Condition) Size() (n int) {
	if m == nil {
		return 0
	}
	var l int
	_ = l
	if m.IntervalType != 0 {
		n += 1 + sovCondition(uint64(m.IntervalType))
	}
	if m.Number != 0 {
		n += 1 + sovCondition(uint64(m.Number))
	}
	return n
}

func sovCondition(x uint64) (n int) {
	return (math_bits.Len64(x|1) + 6) / 7
}
func sozCondition(x uint64) (n int) {
	return sovCondition(uint64((x << 1) ^ uint64((int64(x) >> 63))))
}
func (m *Condition) Unmarshal(dAtA []byte) error {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		preIndex := iNdEx
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return ErrIntOverflowCondition
			}
			if iNdEx >= l {
				return io.ErrUnexpectedEOF
			}
			b := dAtA[iNdEx]
			iNdEx++
			wire |= uint64(b&0x7F) << shift
			if b < 0x80 {
				break
			}
		}
		fieldNum := int32(wire >> 3)
		wireType := int(wire & 0x7)
		if wireType == 4 {
			return fmt.Errorf("proto: Condition: wiretype end group for non-group")
		}
		if fieldNum <= 0 {
			return fmt.Errorf("proto: Condition: illegal tag %d (wire type %d)", fieldNum, wire)
		}
		switch fieldNum {
		case 1:
			if wireType != 0 {
				return fmt.Errorf("proto: wrong wireType = %d for field IntervalType", wireType)
			}
			m.IntervalType = 0
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowCondition
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				m.IntervalType |= uint64(b&0x7F) << shift
				if b < 0x80 {
					break
				}
			}
		case 2:
			if wireType != 0 {
				return fmt.Errorf("proto: wrong wireType = %d for field Number", wireType)
			}
			m.Number = 0
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowCondition
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				m.Number |= uint64(b&0x7F) << shift
				if b < 0x80 {
					break
				}
			}
		default:
			iNdEx = preIndex
			skippy, err := skipCondition(dAtA[iNdEx:])
			if err != nil {
				return err
			}
			if (skippy < 0) || (iNdEx+skippy) < 0 {
				return ErrInvalidLengthCondition
			}
			if (iNdEx + skippy) > l {
				return io.ErrUnexpectedEOF
			}
			iNdEx += skippy
		}
	}

	if iNdEx > l {
		return io.ErrUnexpectedEOF
	}
	return nil
}
func skipCondition(dAtA []byte) (n int, err error) {
	l := len(dAtA)
	iNdEx := 0
	depth := 0
	for iNdEx < l {
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return 0, ErrIntOverflowCondition
			}
			if iNdEx >= l {
				return 0, io.ErrUnexpectedEOF
			}
			b := dAtA[iNdEx]
			iNdEx++
			wire |= (uint64(b) & 0x7F) << shift
			if b < 0x80 {
				break
			}
		}
		wireType := int(wire & 0x7)
		switch wireType {
		case 0:
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return 0, ErrIntOverflowCondition
				}
				if iNdEx >= l {
					return 0, io.ErrUnexpectedEOF
				}
				iNdEx++
				if dAtA[iNdEx-1] < 0x80 {
					break
				}
			}
		case 1:
			iNdEx += 8
		case 2:
			var length int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return 0, ErrIntOverflowCondition
				}
				if iNdEx >= l {
					return 0, io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				length |= (int(b) & 0x7F) << shift
				if b < 0x80 {
					break
				}
			}
			if length < 0 {
				return 0, ErrInvalidLengthCondition
			}
			iNdEx += length
		case 3:
			depth++
		case 4:
			if depth == 0 {
				return 0, ErrUnexpectedEndOfGroupCondition
			}
			depth--
		case 5:
			iNdEx += 4
		default:
			return 0, fmt.Errorf("proto: illegal wireType %d", wireType)
		}
		if iNdEx < 0 {
			return 0, ErrInvalidLengthCondition
		}
		if depth == 0 {
			return iNdEx, nil
		}
	}
	return 0, io.ErrUnexpectedEOF
}

var (
	ErrInvalidLengthCondition        = fmt.Errorf("proto: negative length found during unmarshaling")
	ErrIntOverflowCondition          = fmt.Errorf("proto: integer overflow")
	ErrUnexpectedEndOfGroupCondition = fmt.Errorf("proto: unexpected end of group")
)
