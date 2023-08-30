// Code generated by protoc-gen-gogo. DO NOT EDIT.
// source: specy/specy/genesis.proto

package types

import (
	fmt "fmt"
	_ "github.com/gogo/protobuf/gogoproto"
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

// GenesisState defines the specy module's genesis state.
type GenesisState struct {
	Params                Params                 `protobuf:"bytes,1,opt,name=params,proto3" json:"params"`
	TaskList              []Task                 `protobuf:"bytes,2,rep,name=taskList,proto3" json:"taskList"`
	ExecutorList          []Executor             `protobuf:"bytes,3,rep,name=executorList,proto3" json:"executorList"`
	DepositList           []Deposit              `protobuf:"bytes,4,rep,name=depositList,proto3" json:"depositList"`
	CurrentExecutorStatus *CurrentExecutorStatus `protobuf:"bytes,5,opt,name=currentExecutorStatus,proto3" json:"currentExecutorStatus,omitempty"`
	HistoryExecuteCount   *HistoryExecuteCount   `protobuf:"bytes,6,opt,name=historyExecuteCount,proto3" json:"historyExecuteCount,omitempty"`
	ExecuteRecordList     []ExecuteRecord        `protobuf:"bytes,7,rep,name=executeRecordList,proto3" json:"executeRecordList"`
}

func (m *GenesisState) Reset()         { *m = GenesisState{} }
func (m *GenesisState) String() string { return proto.CompactTextString(m) }
func (*GenesisState) ProtoMessage()    {}
func (*GenesisState) Descriptor() ([]byte, []int) {
	return fileDescriptor_df83825a7444079f, []int{0}
}
func (m *GenesisState) XXX_Unmarshal(b []byte) error {
	return m.Unmarshal(b)
}
func (m *GenesisState) XXX_Marshal(b []byte, deterministic bool) ([]byte, error) {
	if deterministic {
		return xxx_messageInfo_GenesisState.Marshal(b, m, deterministic)
	} else {
		b = b[:cap(b)]
		n, err := m.MarshalToSizedBuffer(b)
		if err != nil {
			return nil, err
		}
		return b[:n], nil
	}
}
func (m *GenesisState) XXX_Merge(src proto.Message) {
	xxx_messageInfo_GenesisState.Merge(m, src)
}
func (m *GenesisState) XXX_Size() int {
	return m.Size()
}
func (m *GenesisState) XXX_DiscardUnknown() {
	xxx_messageInfo_GenesisState.DiscardUnknown(m)
}

var xxx_messageInfo_GenesisState proto.InternalMessageInfo

func (m *GenesisState) GetParams() Params {
	if m != nil {
		return m.Params
	}
	return Params{}
}

func (m *GenesisState) GetTaskList() []Task {
	if m != nil {
		return m.TaskList
	}
	return nil
}

func (m *GenesisState) GetExecutorList() []Executor {
	if m != nil {
		return m.ExecutorList
	}
	return nil
}

func (m *GenesisState) GetDepositList() []Deposit {
	if m != nil {
		return m.DepositList
	}
	return nil
}

func (m *GenesisState) GetCurrentExecutorStatus() *CurrentExecutorStatus {
	if m != nil {
		return m.CurrentExecutorStatus
	}
	return nil
}

func (m *GenesisState) GetHistoryExecuteCount() *HistoryExecuteCount {
	if m != nil {
		return m.HistoryExecuteCount
	}
	return nil
}

func (m *GenesisState) GetExecuteRecordList() []ExecuteRecord {
	if m != nil {
		return m.ExecuteRecordList
	}
	return nil
}

func init() {
	proto.RegisterType((*GenesisState)(nil), "specynetwork.specy.specy.GenesisState")
}

func init() { proto.RegisterFile("specy/specy/genesis.proto", fileDescriptor_df83825a7444079f) }

var fileDescriptor_df83825a7444079f = []byte{
	// 418 bytes of a gzipped FileDescriptorProto
	0x1f, 0x8b, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xff, 0x84, 0x93, 0x4f, 0x6b, 0xe2, 0x40,
	0x18, 0xc6, 0x93, 0xd5, 0x75, 0x97, 0xd1, 0xcb, 0xce, 0xee, 0x96, 0x34, 0x87, 0x34, 0xf5, 0xa2,
	0x85, 0x1a, 0xc1, 0xde, 0x4b, 0xd1, 0xfe, 0x05, 0x0f, 0x25, 0xf6, 0xd4, 0x1e, 0x42, 0x8c, 0x43,
	0x0c, 0x62, 0x26, 0xcc, 0x4c, 0xa8, 0x7e, 0x8b, 0x7e, 0x2c, 0x4f, 0xc5, 0x63, 0x4f, 0xa5, 0xe8,
	0x17, 0x29, 0xce, 0xbc, 0x29, 0x11, 0x0d, 0xbd, 0x04, 0x9d, 0xf7, 0x79, 0x7e, 0x6f, 0xe6, 0x79,
	0xdf, 0xa0, 0x43, 0x9e, 0x90, 0x60, 0xde, 0x56, 0xcf, 0x90, 0xc4, 0x84, 0x47, 0xdc, 0x49, 0x18,
	0x15, 0x14, 0x1b, 0xf2, 0x30, 0x26, 0xe2, 0x99, 0xb2, 0x89, 0x23, 0xff, 0xa8, 0xa7, 0xf9, 0x2f,
	0xa4, 0x21, 0x95, 0xa2, 0xf6, 0xe6, 0x97, 0xd2, 0x9b, 0x46, 0x1e, 0x95, 0xf8, 0xcc, 0x9f, 0x02,
	0xc9, 0x3c, 0xc8, 0x57, 0x84, 0xcf, 0x27, 0x70, 0x6e, 0xe6, 0xcf, 0xc9, 0x8c, 0x04, 0xa9, 0xa0,
	0x0c, 0x6a, 0x5b, 0x2f, 0x36, 0x22, 0x09, 0xe5, 0x91, 0x80, 0xd2, 0x49, 0xbe, 0x14, 0xa4, 0x8c,
	0x91, 0x58, 0x78, 0x99, 0xdd, 0xe3, 0xc2, 0x17, 0x69, 0xd6, 0xb9, 0x91, 0x97, 0x8e, 0x23, 0x2e,
	0x28, 0x9b, 0x83, 0x94, 0x78, 0x01, 0x4d, 0xe3, 0x8c, 0x69, 0xef, 0xbe, 0x0a, 0xf1, 0x18, 0x09,
	0x28, 0x1b, 0x29, 0x45, 0xfd, 0xb5, 0x8c, 0x6a, 0x37, 0x2a, 0xa0, 0x81, 0xf0, 0x05, 0xc1, 0xe7,
	0xa8, 0xa2, 0x6e, 0x69, 0xe8, 0xb6, 0xde, 0xac, 0x76, 0x6c, 0xa7, 0x28, 0x30, 0xe7, 0x5e, 0xea,
	0xba, 0xe5, 0xc5, 0xfb, 0x91, 0xe6, 0x82, 0x0b, 0x5f, 0xa0, 0xdf, 0x9b, 0x2c, 0xfa, 0x11, 0x17,
	0xc6, 0x0f, 0xbb, 0xd4, 0xac, 0x76, 0xac, 0x62, 0xc2, 0x83, 0xcf, 0x27, 0xe0, 0xff, 0x72, 0xe1,
	0x3e, 0xaa, 0x65, 0xd7, 0x96, 0x94, 0x92, 0xa4, 0xd4, 0x8b, 0x29, 0x57, 0xa0, 0x06, 0xd2, 0x96,
	0x1b, 0xdf, 0xa1, 0x2a, 0xe4, 0x2c, 0x61, 0x65, 0x09, 0x3b, 0x2e, 0x86, 0x5d, 0x2a, 0x31, 0xb0,
	0xf2, 0x5e, 0x4c, 0xd0, 0x7f, 0x98, 0x4b, 0xd6, 0x71, 0x20, 0xa7, 0x62, 0xfc, 0x94, 0x49, 0xb5,
	0x8b, 0xa1, 0xbd, 0x7d, 0x36, 0x77, 0x3f, 0x0d, 0x7b, 0xe8, 0x2f, 0xcc, 0x54, 0x15, 0x48, 0x6f,
	0x33, 0x51, 0xa3, 0x22, 0x9b, 0xb4, 0x8a, 0x9b, 0xdc, 0xee, 0x9a, 0xdc, 0x7d, 0x24, 0xfc, 0x84,
	0xfe, 0xc0, 0x2e, 0xb8, 0x72, 0x15, 0x64, 0x30, 0xbf, 0x64, 0x30, 0x8d, 0xef, 0x52, 0x06, 0x0b,
	0xc4, 0xb3, 0xcb, 0xe9, 0x5e, 0x2f, 0x56, 0x96, 0xbe, 0x5c, 0x59, 0xfa, 0xc7, 0xca, 0xd2, 0x5f,
	0xd6, 0x96, 0xb6, 0x5c, 0x5b, 0xda, 0xdb, 0xda, 0xd2, 0x1e, 0x4f, 0xc3, 0x48, 0x8c, 0xd3, 0xa1,
	0x13, 0xd0, 0xa9, 0xda, 0xc8, 0x16, 0xb4, 0x81, 0xfd, 0x9c, 0x65, 0x9f, 0xd2, 0x3c, 0x21, 0x7c,
	0x58, 0x91, 0xfb, 0x79, 0xf6, 0x19, 0x00, 0x00, 0xff, 0xff, 0x9d, 0xd5, 0x35, 0xfc, 0xcb, 0x03,
	0x00, 0x00,
}

func (m *GenesisState) Marshal() (dAtA []byte, err error) {
	size := m.Size()
	dAtA = make([]byte, size)
	n, err := m.MarshalToSizedBuffer(dAtA[:size])
	if err != nil {
		return nil, err
	}
	return dAtA[:n], nil
}

func (m *GenesisState) MarshalTo(dAtA []byte) (int, error) {
	size := m.Size()
	return m.MarshalToSizedBuffer(dAtA[:size])
}

func (m *GenesisState) MarshalToSizedBuffer(dAtA []byte) (int, error) {
	i := len(dAtA)
	_ = i
	var l int
	_ = l
	if len(m.ExecuteRecordList) > 0 {
		for iNdEx := len(m.ExecuteRecordList) - 1; iNdEx >= 0; iNdEx-- {
			{
				size, err := m.ExecuteRecordList[iNdEx].MarshalToSizedBuffer(dAtA[:i])
				if err != nil {
					return 0, err
				}
				i -= size
				i = encodeVarintGenesis(dAtA, i, uint64(size))
			}
			i--
			dAtA[i] = 0x3a
		}
	}
	if m.HistoryExecuteCount != nil {
		{
			size, err := m.HistoryExecuteCount.MarshalToSizedBuffer(dAtA[:i])
			if err != nil {
				return 0, err
			}
			i -= size
			i = encodeVarintGenesis(dAtA, i, uint64(size))
		}
		i--
		dAtA[i] = 0x32
	}
	if m.CurrentExecutorStatus != nil {
		{
			size, err := m.CurrentExecutorStatus.MarshalToSizedBuffer(dAtA[:i])
			if err != nil {
				return 0, err
			}
			i -= size
			i = encodeVarintGenesis(dAtA, i, uint64(size))
		}
		i--
		dAtA[i] = 0x2a
	}
	if len(m.DepositList) > 0 {
		for iNdEx := len(m.DepositList) - 1; iNdEx >= 0; iNdEx-- {
			{
				size, err := m.DepositList[iNdEx].MarshalToSizedBuffer(dAtA[:i])
				if err != nil {
					return 0, err
				}
				i -= size
				i = encodeVarintGenesis(dAtA, i, uint64(size))
			}
			i--
			dAtA[i] = 0x22
		}
	}
	if len(m.ExecutorList) > 0 {
		for iNdEx := len(m.ExecutorList) - 1; iNdEx >= 0; iNdEx-- {
			{
				size, err := m.ExecutorList[iNdEx].MarshalToSizedBuffer(dAtA[:i])
				if err != nil {
					return 0, err
				}
				i -= size
				i = encodeVarintGenesis(dAtA, i, uint64(size))
			}
			i--
			dAtA[i] = 0x1a
		}
	}
	if len(m.TaskList) > 0 {
		for iNdEx := len(m.TaskList) - 1; iNdEx >= 0; iNdEx-- {
			{
				size, err := m.TaskList[iNdEx].MarshalToSizedBuffer(dAtA[:i])
				if err != nil {
					return 0, err
				}
				i -= size
				i = encodeVarintGenesis(dAtA, i, uint64(size))
			}
			i--
			dAtA[i] = 0x12
		}
	}
	{
		size, err := m.Params.MarshalToSizedBuffer(dAtA[:i])
		if err != nil {
			return 0, err
		}
		i -= size
		i = encodeVarintGenesis(dAtA, i, uint64(size))
	}
	i--
	dAtA[i] = 0xa
	return len(dAtA) - i, nil
}

func encodeVarintGenesis(dAtA []byte, offset int, v uint64) int {
	offset -= sovGenesis(v)
	base := offset
	for v >= 1<<7 {
		dAtA[offset] = uint8(v&0x7f | 0x80)
		v >>= 7
		offset++
	}
	dAtA[offset] = uint8(v)
	return base
}
func (m *GenesisState) Size() (n int) {
	if m == nil {
		return 0
	}
	var l int
	_ = l
	l = m.Params.Size()
	n += 1 + l + sovGenesis(uint64(l))
	if len(m.TaskList) > 0 {
		for _, e := range m.TaskList {
			l = e.Size()
			n += 1 + l + sovGenesis(uint64(l))
		}
	}
	if len(m.ExecutorList) > 0 {
		for _, e := range m.ExecutorList {
			l = e.Size()
			n += 1 + l + sovGenesis(uint64(l))
		}
	}
	if len(m.DepositList) > 0 {
		for _, e := range m.DepositList {
			l = e.Size()
			n += 1 + l + sovGenesis(uint64(l))
		}
	}
	if m.CurrentExecutorStatus != nil {
		l = m.CurrentExecutorStatus.Size()
		n += 1 + l + sovGenesis(uint64(l))
	}
	if m.HistoryExecuteCount != nil {
		l = m.HistoryExecuteCount.Size()
		n += 1 + l + sovGenesis(uint64(l))
	}
	if len(m.ExecuteRecordList) > 0 {
		for _, e := range m.ExecuteRecordList {
			l = e.Size()
			n += 1 + l + sovGenesis(uint64(l))
		}
	}
	return n
}

func sovGenesis(x uint64) (n int) {
	return (math_bits.Len64(x|1) + 6) / 7
}
func sozGenesis(x uint64) (n int) {
	return sovGenesis(uint64((x << 1) ^ uint64((int64(x) >> 63))))
}
func (m *GenesisState) Unmarshal(dAtA []byte) error {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		preIndex := iNdEx
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return ErrIntOverflowGenesis
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
			return fmt.Errorf("proto: GenesisState: wiretype end group for non-group")
		}
		if fieldNum <= 0 {
			return fmt.Errorf("proto: GenesisState: illegal tag %d (wire type %d)", fieldNum, wire)
		}
		switch fieldNum {
		case 1:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field Params", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowGenesis
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				msglen |= int(b&0x7F) << shift
				if b < 0x80 {
					break
				}
			}
			if msglen < 0 {
				return ErrInvalidLengthGenesis
			}
			postIndex := iNdEx + msglen
			if postIndex < 0 {
				return ErrInvalidLengthGenesis
			}
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			if err := m.Params.Unmarshal(dAtA[iNdEx:postIndex]); err != nil {
				return err
			}
			iNdEx = postIndex
		case 2:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field TaskList", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowGenesis
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				msglen |= int(b&0x7F) << shift
				if b < 0x80 {
					break
				}
			}
			if msglen < 0 {
				return ErrInvalidLengthGenesis
			}
			postIndex := iNdEx + msglen
			if postIndex < 0 {
				return ErrInvalidLengthGenesis
			}
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.TaskList = append(m.TaskList, Task{})
			if err := m.TaskList[len(m.TaskList)-1].Unmarshal(dAtA[iNdEx:postIndex]); err != nil {
				return err
			}
			iNdEx = postIndex
		case 3:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field ExecutorList", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowGenesis
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				msglen |= int(b&0x7F) << shift
				if b < 0x80 {
					break
				}
			}
			if msglen < 0 {
				return ErrInvalidLengthGenesis
			}
			postIndex := iNdEx + msglen
			if postIndex < 0 {
				return ErrInvalidLengthGenesis
			}
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.ExecutorList = append(m.ExecutorList, Executor{})
			if err := m.ExecutorList[len(m.ExecutorList)-1].Unmarshal(dAtA[iNdEx:postIndex]); err != nil {
				return err
			}
			iNdEx = postIndex
		case 4:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field DepositList", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowGenesis
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				msglen |= int(b&0x7F) << shift
				if b < 0x80 {
					break
				}
			}
			if msglen < 0 {
				return ErrInvalidLengthGenesis
			}
			postIndex := iNdEx + msglen
			if postIndex < 0 {
				return ErrInvalidLengthGenesis
			}
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.DepositList = append(m.DepositList, Deposit{})
			if err := m.DepositList[len(m.DepositList)-1].Unmarshal(dAtA[iNdEx:postIndex]); err != nil {
				return err
			}
			iNdEx = postIndex
		case 5:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field CurrentExecutorStatus", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowGenesis
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				msglen |= int(b&0x7F) << shift
				if b < 0x80 {
					break
				}
			}
			if msglen < 0 {
				return ErrInvalidLengthGenesis
			}
			postIndex := iNdEx + msglen
			if postIndex < 0 {
				return ErrInvalidLengthGenesis
			}
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			if m.CurrentExecutorStatus == nil {
				m.CurrentExecutorStatus = &CurrentExecutorStatus{}
			}
			if err := m.CurrentExecutorStatus.Unmarshal(dAtA[iNdEx:postIndex]); err != nil {
				return err
			}
			iNdEx = postIndex
		case 6:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field HistoryExecuteCount", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowGenesis
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				msglen |= int(b&0x7F) << shift
				if b < 0x80 {
					break
				}
			}
			if msglen < 0 {
				return ErrInvalidLengthGenesis
			}
			postIndex := iNdEx + msglen
			if postIndex < 0 {
				return ErrInvalidLengthGenesis
			}
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			if m.HistoryExecuteCount == nil {
				m.HistoryExecuteCount = &HistoryExecuteCount{}
			}
			if err := m.HistoryExecuteCount.Unmarshal(dAtA[iNdEx:postIndex]); err != nil {
				return err
			}
			iNdEx = postIndex
		case 7:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field ExecuteRecordList", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowGenesis
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				msglen |= int(b&0x7F) << shift
				if b < 0x80 {
					break
				}
			}
			if msglen < 0 {
				return ErrInvalidLengthGenesis
			}
			postIndex := iNdEx + msglen
			if postIndex < 0 {
				return ErrInvalidLengthGenesis
			}
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.ExecuteRecordList = append(m.ExecuteRecordList, ExecuteRecord{})
			if err := m.ExecuteRecordList[len(m.ExecuteRecordList)-1].Unmarshal(dAtA[iNdEx:postIndex]); err != nil {
				return err
			}
			iNdEx = postIndex
		default:
			iNdEx = preIndex
			skippy, err := skipGenesis(dAtA[iNdEx:])
			if err != nil {
				return err
			}
			if (skippy < 0) || (iNdEx+skippy) < 0 {
				return ErrInvalidLengthGenesis
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
func skipGenesis(dAtA []byte) (n int, err error) {
	l := len(dAtA)
	iNdEx := 0
	depth := 0
	for iNdEx < l {
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return 0, ErrIntOverflowGenesis
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
					return 0, ErrIntOverflowGenesis
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
					return 0, ErrIntOverflowGenesis
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
				return 0, ErrInvalidLengthGenesis
			}
			iNdEx += length
		case 3:
			depth++
		case 4:
			if depth == 0 {
				return 0, ErrUnexpectedEndOfGroupGenesis
			}
			depth--
		case 5:
			iNdEx += 4
		default:
			return 0, fmt.Errorf("proto: illegal wireType %d", wireType)
		}
		if iNdEx < 0 {
			return 0, ErrInvalidLengthGenesis
		}
		if depth == 0 {
			return iNdEx, nil
		}
	}
	return 0, io.ErrUnexpectedEOF
}

var (
	ErrInvalidLengthGenesis        = fmt.Errorf("proto: negative length found during unmarshaling")
	ErrIntOverflowGenesis          = fmt.Errorf("proto: integer overflow")
	ErrUnexpectedEndOfGroupGenesis = fmt.Errorf("proto: unexpected end of group")
)