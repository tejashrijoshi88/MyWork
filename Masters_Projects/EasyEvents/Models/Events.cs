using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Threading.Tasks;

namespace EasyEvents.Models
{
    public class Events
    {     
        [Key]
        [DatabaseGenerated(DatabaseGeneratedOption.Identity)]
        public int EventId { get; set; }
        public int HostId { get; set; }
        public virtual Users User { get; set; }
        public int EventTypeId { get; set; }
        public virtual EventType EventType { get; set; }
        public int VenueId { get; set; }
        public virtual Venues Venue { get; set; }
        public string EventName { get; set; }
        public string Description { get; set; }
        public DateTime DateTime { get; set; }
        public string Time { get; set; }
    }
}

