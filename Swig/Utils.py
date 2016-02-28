# This file was automatically generated by SWIG (http://www.swig.org).
# Version 3.0.8
#
# Do not make changes to this file unless you know what you are doing--modify
# the SWIG interface file instead.





from sys import version_info
if version_info >= (2, 6, 0):
    def swig_import_helper():
        from os.path import dirname
        import imp
        fp = None
        try:
            fp, pathname, description = imp.find_module('_Utils', [dirname(__file__)])
        except ImportError:
            import _Utils
            return _Utils
        if fp is not None:
            try:
                _mod = imp.load_module('_Utils', fp, pathname, description)
            finally:
                fp.close()
            return _mod
    _Utils = swig_import_helper()
    del swig_import_helper
else:
    import _Utils
del version_info
try:
    _swig_property = property
except NameError:
    pass  # Python < 2.2 doesn't have 'property'.


def _swig_setattr_nondynamic(self, class_type, name, value, static=1):
    if (name == "thisown"):
        return self.this.own(value)
    if (name == "this"):
        if type(value).__name__ == 'SwigPyObject':
            self.__dict__[name] = value
            return
    method = class_type.__swig_setmethods__.get(name, None)
    if method:
        return method(self, value)
    if (not static):
        if _newclass:
            object.__setattr__(self, name, value)
        else:
            self.__dict__[name] = value
    else:
        raise AttributeError("You cannot add attributes to %s" % self)


def _swig_setattr(self, class_type, name, value):
    return _swig_setattr_nondynamic(self, class_type, name, value, 0)


def _swig_getattr_nondynamic(self, class_type, name, static=1):
    if (name == "thisown"):
        return self.this.own()
    method = class_type.__swig_getmethods__.get(name, None)
    if method:
        return method(self)
    if (not static):
        return object.__getattr__(self, name)
    else:
        raise AttributeError(name)

def _swig_getattr(self, class_type, name):
    return _swig_getattr_nondynamic(self, class_type, name, 0)


def _swig_repr(self):
    try:
        strthis = "proxy of " + self.this.__repr__()
    except Exception:
        strthis = ""
    return "<%s.%s; %s >" % (self.__class__.__module__, self.__class__.__name__, strthis,)

try:
    _object = object
    _newclass = 1
except AttributeError:
    class _object:
        pass
    _newclass = 0



_Utils.Axis_X_swigconstant(_Utils)
Axis_X = _Utils.Axis_X

_Utils.Axis_Y_swigconstant(_Utils)
Axis_Y = _Utils.Axis_Y

_Utils.Axis_Z_swigconstant(_Utils)
Axis_Z = _Utils.Axis_Z

_Utils.AngleValueType_degree_swigconstant(_Utils)
AngleValueType_degree = _Utils.AngleValueType_degree

_Utils.AngleValueType_radian_swigconstant(_Utils)
AngleValueType_radian = _Utils.AngleValueType_radian
class Transformer3D(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Transformer3D, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Transformer3D, name)
    __repr__ = _swig_repr
    __swig_setmethods__["rotation_matrix_X"] = _Utils.Transformer3D_rotation_matrix_X_set
    __swig_getmethods__["rotation_matrix_X"] = _Utils.Transformer3D_rotation_matrix_X_get
    if _newclass:
        rotation_matrix_X = _swig_property(_Utils.Transformer3D_rotation_matrix_X_get, _Utils.Transformer3D_rotation_matrix_X_set)
    __swig_setmethods__["rotation_matrix_Y"] = _Utils.Transformer3D_rotation_matrix_Y_set
    __swig_getmethods__["rotation_matrix_Y"] = _Utils.Transformer3D_rotation_matrix_Y_get
    if _newclass:
        rotation_matrix_Y = _swig_property(_Utils.Transformer3D_rotation_matrix_Y_get, _Utils.Transformer3D_rotation_matrix_Y_set)
    __swig_setmethods__["rotation_matrix_Z"] = _Utils.Transformer3D_rotation_matrix_Z_set
    __swig_getmethods__["rotation_matrix_Z"] = _Utils.Transformer3D_rotation_matrix_Z_get
    if _newclass:
        rotation_matrix_Z = _swig_property(_Utils.Transformer3D_rotation_matrix_Z_get, _Utils.Transformer3D_rotation_matrix_Z_set)

    def __init__(self):
        this = _Utils.new_Transformer3D()
        try:
            self.this.append(this)
        except Exception:
            self.this = this
    __swig_getmethods__["Rotate"] = lambda x: _Utils.Transformer3D_Rotate
    if _newclass:
        Rotate = staticmethod(_Utils.Transformer3D_Rotate)
    __swig_getmethods__["SetRotationAngle"] = lambda x: _Utils.Transformer3D_SetRotationAngle
    if _newclass:
        SetRotationAngle = staticmethod(_Utils.Transformer3D_SetRotationAngle)
    __swig_destroy__ = _Utils.delete_Transformer3D
    __del__ = lambda self: None
Transformer3D_swigregister = _Utils.Transformer3D_swigregister
Transformer3D_swigregister(Transformer3D)
cvar = _Utils.cvar

def Transformer3D_Rotate(angle, value, axis):
    return _Utils.Transformer3D_Rotate(angle, value, axis)
Transformer3D_Rotate = _Utils.Transformer3D_Rotate

def Transformer3D_SetRotationAngle(axis, angle):
    return _Utils.Transformer3D_SetRotationAngle(axis, angle)
Transformer3D_SetRotationAngle = _Utils.Transformer3D_SetRotationAngle

class Location(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Location, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Location, name)
    __repr__ = _swig_repr
    __swig_setmethods__["name"] = _Utils.Location_name_set
    __swig_getmethods__["name"] = _Utils.Location_name_get
    if _newclass:
        name = _swig_property(_Utils.Location_name_get, _Utils.Location_name_set)
    __swig_setmethods__["id"] = _Utils.Location_id_set
    __swig_getmethods__["id"] = _Utils.Location_id_get
    if _newclass:
        id = _swig_property(_Utils.Location_id_get, _Utils.Location_id_set)

    def __init__(self, *args):
        this = _Utils.new_Location(*args)
        try:
            self.this.append(this)
        except Exception:
            self.this = this

    def __eq__(self, other):
        return _Utils.Location___eq__(self, other)

    def __ne__(self, other):
        return _Utils.Location___ne__(self, other)
    __swig_destroy__ = _Utils.delete_Location
    __del__ = lambda self: None
Location_swigregister = _Utils.Location_swigregister
Location_swigregister(Location)

class LocationBase(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, LocationBase, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, LocationBase, name)
    __repr__ = _swig_repr
    __swig_getmethods__["Init"] = lambda x: _Utils.LocationBase_Init
    if _newclass:
        Init = staticmethod(_Utils.LocationBase_Init)
    __swig_getmethods__["Add"] = lambda x: _Utils.LocationBase_Add
    if _newclass:
        Add = staticmethod(_Utils.LocationBase_Add)
    __swig_getmethods__["Clear"] = lambda x: _Utils.LocationBase_Clear
    if _newclass:
        Clear = staticmethod(_Utils.LocationBase_Clear)
    __swig_getmethods__["IsInitialized"] = lambda x: _Utils.LocationBase_IsInitialized
    if _newclass:
        IsInitialized = staticmethod(_Utils.LocationBase_IsInitialized)
    __swig_getmethods__["Get"] = lambda x: _Utils.LocationBase_Get
    if _newclass:
        Get = staticmethod(_Utils.LocationBase_Get)

    def __init__(self):
        this = _Utils.new_LocationBase()
        try:
            self.this.append(this)
        except Exception:
            self.this = this
    __swig_destroy__ = _Utils.delete_LocationBase
    __del__ = lambda self: None
LocationBase_swigregister = _Utils.LocationBase_swigregister
LocationBase_swigregister(LocationBase)

def LocationBase_Init():
    return _Utils.LocationBase_Init()
LocationBase_Init = _Utils.LocationBase_Init

def LocationBase_Add(loc):
    return _Utils.LocationBase_Add(loc)
LocationBase_Add = _Utils.LocationBase_Add

def LocationBase_Clear():
    return _Utils.LocationBase_Clear()
LocationBase_Clear = _Utils.LocationBase_Clear

def LocationBase_IsInitialized():
    return _Utils.LocationBase_IsInitialized()
LocationBase_IsInitialized = _Utils.LocationBase_IsInitialized

def LocationBase_Get(*args):
    return _Utils.LocationBase_Get(*args)
LocationBase_Get = _Utils.LocationBase_Get


def WorldPositionToBlockCoords(position):
    return _Utils.WorldPositionToBlockCoords(position)
WorldPositionToBlockCoords = _Utils.WorldPositionToBlockCoords

def BlockCoordsToWorldPosition(coords):
    return _Utils.BlockCoordsToWorldPosition(coords)
BlockCoordsToWorldPosition = _Utils.BlockCoordsToWorldPosition

def WorldPositionToChunkCoords(position):
    return _Utils.WorldPositionToChunkCoords(position)
WorldPositionToChunkCoords = _Utils.WorldPositionToChunkCoords

def ToGlobalChunkCoords(block_coordinates, coordinates):
    return _Utils.ToGlobalChunkCoords(block_coordinates, coordinates)
ToGlobalChunkCoords = _Utils.ToGlobalChunkCoords
class Triangle(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Triangle, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Triangle, name)
    __repr__ = _swig_repr
    __swig_setmethods__["indices"] = _Utils.Triangle_indices_set
    __swig_getmethods__["indices"] = _Utils.Triangle_indices_get
    if _newclass:
        indices = _swig_property(_Utils.Triangle_indices_get, _Utils.Triangle_indices_set)

    def __init__(self):
        this = _Utils.new_Triangle()
        try:
            self.this.append(this)
        except Exception:
            self.this = this
    __swig_destroy__ = _Utils.delete_Triangle
    __del__ = lambda self: None
Triangle_swigregister = _Utils.Triangle_swigregister
Triangle_swigregister(Triangle)
Mver = cvar.Mver
Mhdr = cvar.Mhdr
Mcin = cvar.Mcin
Mtex = cvar.Mtex
Mmdx = cvar.Mmdx
Mmid = cvar.Mmid
Mwmo = cvar.Mwmo
Mwid = cvar.Mwid
Mddf = cvar.Mddf
Modf = cvar.Modf
Mh2o = cvar.Mh2o
Mfbo = cvar.Mfbo
Mtxf = cvar.Mtxf
Mtxp = cvar.Mtxp
Mcnk = cvar.Mcnk
Mcvt = cvar.Mcvt
Mcrd = cvar.Mcrd
Mcrw = cvar.Mcrw
Mohd = cvar.Mohd
Mogp = cvar.Mogp
Movt = cvar.Movt
Movi = cvar.Movi
BlockSize = cvar.BlockSize
ChunkSize = cvar.ChunkSize
UnitSize = cvar.UnitSize
MapSize = cvar.MapSize
MapMidPoint = cvar.MapMidPoint

class Color(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Color, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Color, name)
    __repr__ = _swig_repr
    __swig_setmethods__["r"] = _Utils.Color_r_set
    __swig_getmethods__["r"] = _Utils.Color_r_get
    if _newclass:
        r = _swig_property(_Utils.Color_r_get, _Utils.Color_r_set)
    __swig_setmethods__["g"] = _Utils.Color_g_set
    __swig_getmethods__["g"] = _Utils.Color_g_get
    if _newclass:
        g = _swig_property(_Utils.Color_g_get, _Utils.Color_g_set)
    __swig_setmethods__["b"] = _Utils.Color_b_set
    __swig_getmethods__["b"] = _Utils.Color_b_get
    if _newclass:
        b = _swig_property(_Utils.Color_b_get, _Utils.Color_b_set)
    __swig_setmethods__["a"] = _Utils.Color_a_set
    __swig_getmethods__["a"] = _Utils.Color_a_get
    if _newclass:
        a = _swig_property(_Utils.Color_a_get, _Utils.Color_a_set)

    def __init__(self, *args):
        this = _Utils.new_Color(*args)
        try:
            self.this.append(this)
        except Exception:
            self.this = this
    __swig_destroy__ = _Utils.delete_Color
    __del__ = lambda self: None
Color_swigregister = _Utils.Color_swigregister
Color_swigregister(Color)

class Vertex(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Vertex, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Vertex, name)
    __repr__ = _swig_repr
    __swig_setmethods__["position"] = _Utils.Vertex_position_set
    __swig_getmethods__["position"] = _Utils.Vertex_position_get
    if _newclass:
        position = _swig_property(_Utils.Vertex_position_get, _Utils.Vertex_position_set)
    __swig_setmethods__["color"] = _Utils.Vertex_color_set
    __swig_getmethods__["color"] = _Utils.Vertex_color_get
    if _newclass:
        color = _swig_property(_Utils.Vertex_color_get, _Utils.Vertex_color_set)

    def __init__(self, *args):
        this = _Utils.new_Vertex(*args)
        try:
            self.this.append(this)
        except Exception:
            self.this = this
    __swig_destroy__ = _Utils.delete_Vertex
    __del__ = lambda self: None
Vertex_swigregister = _Utils.Vertex_swigregister
Vertex_swigregister(Vertex)

class BoundingBox(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, BoundingBox, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, BoundingBox, name)
    __repr__ = _swig_repr
    __swig_setmethods__["up"] = _Utils.BoundingBox_up_set
    __swig_getmethods__["up"] = _Utils.BoundingBox_up_get
    if _newclass:
        up = _swig_property(_Utils.BoundingBox_up_get, _Utils.BoundingBox_up_set)
    __swig_setmethods__["down"] = _Utils.BoundingBox_down_set
    __swig_getmethods__["down"] = _Utils.BoundingBox_down_get
    if _newclass:
        down = _swig_property(_Utils.BoundingBox_down_get, _Utils.BoundingBox_down_set)

    def IsInside2D(self, point):
        return _Utils.BoundingBox_IsInside2D(self, point)

    def GetArrayMin(self):
        return _Utils.BoundingBox_GetArrayMin(self)

    def GetArrayMax(self):
        return _Utils.BoundingBox_GetArrayMax(self)

    def __init__(self):
        this = _Utils.new_BoundingBox()
        try:
            self.this.append(this)
        except Exception:
            self.this = this
    __swig_destroy__ = _Utils.delete_BoundingBox
    __del__ = lambda self: None
BoundingBox_swigregister = _Utils.BoundingBox_swigregister
BoundingBox_swigregister(BoundingBox)

class Vector3(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Vector3, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Vector3, name)
    __repr__ = _swig_repr
    __swig_setmethods__["x"] = _Utils.Vector3_x_set
    __swig_getmethods__["x"] = _Utils.Vector3_x_get
    if _newclass:
        x = _swig_property(_Utils.Vector3_x_get, _Utils.Vector3_x_set)
    __swig_setmethods__["y"] = _Utils.Vector3_y_set
    __swig_getmethods__["y"] = _Utils.Vector3_y_get
    if _newclass:
        y = _swig_property(_Utils.Vector3_y_get, _Utils.Vector3_y_set)
    __swig_setmethods__["z"] = _Utils.Vector3_z_set
    __swig_getmethods__["z"] = _Utils.Vector3_z_get
    if _newclass:
        z = _swig_property(_Utils.Vector3_z_get, _Utils.Vector3_z_set)

    def __init__(self, *args):
        this = _Utils.new_Vector3(*args)
        try:
            self.this.append(this)
        except Exception:
            self.this = this

    def __add__(self, right):
        return _Utils.Vector3___add__(self, right)

    def __sub__(self, right):
        return _Utils.Vector3___sub__(self, right)

    def __mul__(self, right):
        return _Utils.Vector3___mul__(self, right)

    def __eq__(self, right):
        return _Utils.Vector3___eq__(self, right)

    def __ne__(self, right):
        return _Utils.Vector3___ne__(self, right)
    __swig_destroy__ = _Utils.delete_Vector3
    __del__ = lambda self: None
Vector3_swigregister = _Utils.Vector3_swigregister
Vector3_swigregister(Vector3)
PI = cvar.PI

class Position(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Position, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Position, name)
    __repr__ = _swig_repr
    __swig_setmethods__["coords"] = _Utils.Position_coords_set
    __swig_getmethods__["coords"] = _Utils.Position_coords_get
    if _newclass:
        coords = _swig_property(_Utils.Position_coords_get, _Utils.Position_coords_set)
    __swig_setmethods__["rotation"] = _Utils.Position_rotation_set
    __swig_getmethods__["rotation"] = _Utils.Position_rotation_get
    if _newclass:
        rotation = _swig_property(_Utils.Position_rotation_get, _Utils.Position_rotation_set)

    def __init__(self, *args):
        this = _Utils.new_Position(*args)
        try:
            self.this.append(this)
        except Exception:
            self.this = this
    __swig_destroy__ = _Utils.delete_Position
    __del__ = lambda self: None
Position_swigregister = _Utils.Position_swigregister
Position_swigregister(Position)

# This file is compatible with both classic and new-style classes.


