#undef TRACE_SYSTEM
#define TRACE_SYSTEM almk

#if !defined(_TRACE_ALMK_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_ALMK_H

#include <linux/tracepoint.h>
#include <linux/types.h>

TRACE_EVENT(almk_vmpressure,
	TP_PROTO(unsigned long pressure, unsigned long other_free,
		 unsigned long other_file),
	TP_ARGS(pressure, other_free, other_file),
	TP_STRUCT__entry(
		__field(unsigned long, pressure)
		__field(unsigned long, other_free)
		__field(unsigned long, other_file)
	),
	TP_fast_assign(
		__entry->pressure = pressure;
		__entry->other_free = other_free;
		__entry->other_file = other_file;
	),
	TP_printk("%lu, %lu, %lu",
		__entry->pressure, __entry->other_free, __entry->other_file)
);

TRACE_EVENT(almk_shrink,
	TP_PROTO(int tsize, int vmpressure, int other_free, int other_file,
		 short adj),
	TP_ARGS(tsize, vmpressure, other_free, other_file, adj),
	TP_STRUCT__entry(
		__field(int, tsize)
		__field(int, vmpressure)
		__field(int, other_free)
		__field(int, other_file)
		__field(short, adj)
	),
	TP_fast_assign(
		__entry->tsize = tsize;
		__entry->vmpressure = vmpressure;
		__entry->other_free = other_free;
		__entry->other_file = other_file;
		__entry->adj = adj;
	),
	TP_printk("%d, %d, %d, %d, %d",
		__entry->tsize, __entry->vmpressure,
		__entry->other_free, __entry->other_file, __entry->adj)
);

#endif /* _TRACE_ALMK_H */

/* This part must be outside protection */
#include <trace/define_trace.h>
