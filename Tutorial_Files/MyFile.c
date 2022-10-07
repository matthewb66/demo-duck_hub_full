euprhgobindgbmweth\
s
cgnh
rewet

yh
dog
h
dfgsh
n
can
rat
u
j5
ymnwf
/*-------------------------------------------------------------------------
 * datumGetSize
 *
 * Find the "real" size of a datum, given the datum value,
 * whether it is a "by value", and the declared type length.
 *
 * This is essentially an out-of-line version of the att_addlength()
 * macro in access/tupmacs.h.  We do a tad more error checking though.
 *-------------------------------------------------------------------------
 */
Size
datumGetSize(Datum value, bool typByVal, int typLen)
{
	Size		size;

	if (typByVal)
	{
		/* Pass-by-value types are always fixed-length */
		Assert(typLen > 0 && typLen <= sizeof(Datum));
		size = (Size) typLen;
	}
	else
	{
		if (typLen > 0)
		{
			/* Fixed-length pass-by-ref type */
			size = (Size) typLen;
		}
		else if (typLen == -1)
		{
			/* It is a varlena datatype */
			struct varlena *s = (struct varlena *) DatumGetPointer(value);

			if (!PointerIsValid(s))
				ereport(ERROR,
						(errcode(ERRCODE_DATA_EXCEPTION),
						 errmsg("invalid Datum pointer")));

			size = (Size) VARATT_SIZE(s);
		}
		else if (typLen == -2)
		{
			/* It is a cstring datatype */
			char	   *s = (char *) DatumGetPointer(value);

			if (!PointerIsValid(s))
				ereport(ERROR,
						(errcode(ERRCODE_DATA_EXCEPTION),
						 errmsg("invalid Datum pointer")));

			size = (Size) (strlen(s) + 1);
		}
		else
		{
			elog(ERROR, "invalid typLen: %d", typLen);
			size = 0;			/* keep compiler quiet */
		}
	}

	return size;
}

gh
dos
fed
fsg
we
57y
/**
 * Adds a value to the cache.  If the cache is full, when a new value
 * is added to the cache, it replaces the first of the current values
 * in the cache to have been added (i.e., FIFO).
 * <p>
 * @param key   The key referencing the value added to the cache.
 * @param value The value to add to the cache.
 */
public final synchronized void addElement(Object key, Object value) {
    int index;
    Object obj;
    
    obj = _table.get(key);
    
    if(obj != null) {
        GenericCacheEntry entry;
        
        // Just replace the value.  Technically this upsets the FIFO ordering,
        // but it's expedient.
        entry = (GenericCacheEntry)obj;
        entry._value = value;
        entry._key   = key;
        
        return;
    }
    
    // If we haven't filled the cache yet, put it at the end.
    if(!isFull()) {
        index = _numEntries;
        ++_numEntries;
    } else {
        // Otherwise, replace the current pointer, which takes care of
        // FIFO in a circular fashion.
        index = __curent;
        
        if(++__curent >= _cache.length)
            __curent = 0;
        
        _table.remove(_cache[index]._key);
    }
    
    _cache[index]._value = value;
    _cache[index]._key   = key;
    _table.put(key, _cache[index]);
}

}

re
ur
hf
ghgfdh
ertyureytoyjpoifjh
